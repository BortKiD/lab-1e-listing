#include <memory>
#include <iostream>
#include "application/ArendaService.h"
#include "application/policy/ArendaPolicy.h"
#include "infrastructure/InMemoryArendaRepository.h"
#include "domain/Email.h"
#include "domain/Person.h"
#include "domain/Role.h"
#include "domain/Book.h"
#include "domain/Copy.h"
#include "domain/isbn.h"

int main() {
    auto repository = std::make_shared<InMemoryArendaRepository>();
    auto policy = std::make_shared<DefaultArendaPolicy>();
    ArendaService service(repository, policy);
    Email email("shepard@example.com");
    auto person = std::make_shared<Person>(1, 
        "John Shepard", 
        email);
    person->addRole(std::make_shared<ReaderRole>());

    std::vector<std::string> authors = {"Терри Пратчет"};
    auto book = std::make_shared<Book>("Последний континент", ISBN("5-699-12841-7"), authors, 1998);
    auto copy = std::make_shared<Copy>(1, book);
    auto arenda = service.createArenda(person, copy);

    if (copy->isAvailable()) 
        std::cout << "Copy is available\n";
    else 
        std::cout << "Copy is not available\n";

    arenda->close();

    if (copy->isAvailable()) 
        std::cout << "Copy returned successfully\n";

    return 0;
}