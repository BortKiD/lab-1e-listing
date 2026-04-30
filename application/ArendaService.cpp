#include "ArendaService.h"
#include "policy/ArendaPolicy.h"
#include "../domain/Arenda.h"
#include "../domain/Person.h"
#include "../domain/Copy.h"
#include <algorithm>
#include <memory>
#include <stdexcept>

ArendaService::ArendaService(
    std::shared_ptr<ArendaRepository> repository,
    std::shared_ptr<ArendaPolicy> policy
    ) : 
    repository_(repository),
    policy_(policy) {}

std::shared_ptr<Arenda> ArendaService::createArenda(
    std::shared_ptr<Person> person,
    std::shared_ptr<Copy> copy) 
{
    if (!person) throw std::invalid_argument("Person is null");
    if (!copy) throw std::invalid_argument("Copy is null");
    if (hasOverdueArendas(person->getId()))
        throw std::logic_error("User has overdue book/books!");

    auto active = repository_->findActiveByPerson(person->getId());
    if (!policy_) throw std::logic_error("ArendaPolicy is not set");
    if (!policy_->canCreateArenda(*person, *copy, active))
        throw std::logic_error("Can't issue book");

    auto arenda = std::make_shared<Arenda>(person, copy);
    copy->markAsBorrowed();
    repository_->save(arenda);
    return arenda;
}

void ArendaService::closeArenda(std::shared_ptr<Arenda> arenda)
{
    if (!arenda) throw std::invalid_argument("Arenda is null!");

    arenda->close();
    arenda->getCopy()->markAsReturned();
}

bool ArendaService::hasOverdueArendas(int personId){
    auto arendas = repository_->findActiveByPerson(personId);
    return std::ranges::find(arendas, true, &Arenda::isOverdue) != arendas.end();
}
