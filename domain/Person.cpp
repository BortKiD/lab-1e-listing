#include "Person.h"
#include <stdexcept>
#include <utility>

Person::Person(int id, 
    std::string fullName, 
    std::string email) : 
    id_(id), 
    fullName_(std::move(fullName)),
    email_(std::move(email))
{
    if (fullName_.empty())
        throw std::invalid_argument("Invalid Full Name");
}

int Person::getId() const 
{
    return id_;
}

const std::string& Person::getFullName() const 
{
    return fullName_;
}

const std::string& Person::getEmail() const 
{
    return email_;
}

void Person::addRole(std::shared_ptr<Role> role) 
{
    roles_.push_back(role);
}

bool Person::hasRole(const std::string& roleName) const
{
    for (const auto& role : roles_) 
        if (role->getName() == roleName) 
            return true;
    return false;
}

void Person::changeEmail(const std::string& newEmail) 
{
    if (newEmail.empty())
        throw std::invalid_argument("Email cannot be empty");
    email_ = newEmail;
}
