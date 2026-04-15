#pragma once
#include "../Domain/User.hpp"


class UserRepository {
public:
    virtual User findById(int id) = 0;
    virtual void save(const User& user) = 0;
    virtual ~UserRepository() = default;
};