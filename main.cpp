#include <memory>
#include <iostream>
#include <ostream>
#include "application/ArendaService.h"
#include "domain/Person.h"
#include "infrastructure/InMemoryArendaRepository.h"
int main() {
    auto repository = std::make_shared<InMemoryArendaRepository>();
    // ArendaService arendaService(repository);
    // Mock
    auto person = Person(1, "Andrew", "andrew@example.com");
    auto role = std::make_shared<ReaderRole>();
    person.addRole(role);
    std::cout << person.hasRole("Reader") << std::endl;
    return 0;
}