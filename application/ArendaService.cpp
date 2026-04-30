#include "ArendaService.h"
#include "../infrastructure/ArendaRepository.h"
#include "../domain/Arenda.h"
#include "../domain/Person.h"
#include "../domain/Copy.h"



ArendaService::ArendaService(std::shared_ptr<ArendaRepository> repository)
    : repository_(repository) {}

void ArendaService::issueArenda(int /*personId*/, int /*copyId*/) 
{
    // Реализация сценария выдачи книги
    // Здесь будет:  - поиск читателя; - проверка правил
    //  - создание Arenda; - сохранение через repository_
}

std::shared_ptr<Arenda> ArendaService::createArenda(
std::shared_ptr<Person> person,
std::shared_ptr<Copy> copy)
{
    if (person->hasOverdueArendas()) {
        throw std::logic_error("User has overdue book/books!");
    }
    auto arenda = std::make_shared<Arenda>(person, copy);
    person->addArenda(arenda);
    return arenda;
}

void ArendaService::closeArenda(std::shared_ptr<Arenda> arenda)
{
    if (!arenda)
        throw std::invalid_argument("Arenda is null");
    arenda->close();
}
