#pragma once
#include "UserRepository.hpp"
#include <vector>

class InMemoryUserRepository : public UserRepository {
private:
    std::vector<User> users;

public:
    User findById(int id) override;
    void save(const User& user) override;
};