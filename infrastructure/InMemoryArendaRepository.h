#pragma once
#include "ArendaRepository.h"
#include <vector>

class InMemoryArendaRepository : public
ArendaRepository 
{
public:
    void save(std::shared_ptr<Arenda> arenda) override;
    std::vector<std::shared_ptr<Arenda>> findActiveByPerson(int personId) override;
private:
//std::vector<std::shared_ptr<Arenda>> storage_;
    std::vector<std::shared_ptr<Arenda>> arendas_;
};