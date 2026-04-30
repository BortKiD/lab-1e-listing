#include "ArendaService.h"
#include "../infrastructure/InMemoryArendaRepository.h"
#include "../domain/Arenda.h"
#include "../domain/Person.h"
#include "../domain/Copy.h"
#include <algorithm>
#include <cstddef>
#include <stdexcept>

ArendaService::ArendaService(std::shared_ptr<ArendaRepository> repository)
: repository_(repository) {}

std::shared_ptr<Arenda> ArendaService::createArenda(
    std::shared_ptr<Person> person,
    std::shared_ptr<Copy> copy) 
{
    if (hasOverdueArendas(person->getId()))
        throw std::logic_error("User has overdue book/books!");

    auto active = repository_->findActiveByPerson(person->getId());
    if (active.size() >= static_cast<size_t>(person->getMaxActiveArendas()))
        throw std::logic_error("Arenda's Limit exceeded!");
    
    if (!copy->isAvailable())
        throw std::logic_error("Copy is not available");

    copy->markAsBorrowed();

    auto arenda = std::make_shared<Arenda>(person, copy);
    repository_->save(arenda);
    return arenda;
}

void ArendaService::closeArenda(std::shared_ptr<Arenda> arenda)
{
    if (!arenda)
        throw std::invalid_argument("Arenda is null!");
    arenda->close();
    arenda->getCopy()->markAsReturned();
}

bool ArendaService::hasOverdueArendas(int personId){
    auto arendas = repository_->findActiveByPerson(personId);
    return std::ranges::find(arendas, true, &Arenda::isOverdue) != arendas.end();
}
