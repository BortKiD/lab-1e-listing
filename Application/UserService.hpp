#pragma once
#include "../Infrastructure/UserRepository.hpp"

class UserService {
private:
    UserRepository& repo;

public:
    UserService(UserRepository& repo);

    User getUser(int id);
};