#include "InMemoryArendaRepository.h"
#include "../domain/Arenda.h"
#include "../domain/Person.h"
#include <vector>

void InMemoryArendaRepository::save(std::shared_ptr<Arenda> Arenda) {
    //storage_.push_back(Arenda);
    arendas_.push_back(Arenda);
}

std::vector<std::shared_ptr<Arenda>> 
InMemoryArendaRepository::findActiveByPerson(int personId) {
    std::vector<std::shared_ptr<Arenda>> res;
    for (const auto& arenda : arendas_) {
        if (arenda->getPerson()->getId() == personId && arenda->isActive()) 
        {
            res.push_back(arenda);
        }
    }
    return res;
}