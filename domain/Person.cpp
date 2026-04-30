#include "Person.h"
#include <stdexcept>
#include <utility>
#include <algorithm>

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

const Email& Person::getEmail() const 
{
    return email_;
}

void Person::addRole(std::shared_ptr<Role> role) 
{
    roles_.push_back(role);
}

bool Person::hasRole(const std::string& roleName) const
{
    // for (const auto& role : roles_) 
    //     if (role->getName() == roleName) 
    //         return true;
    // return false;
    return std::ranges::find(roles_, roleName, &Role::getName) != roles_.end();
}

void Person::changeEmail(Email& newEmail) 
{
    email_ = std::move(newEmail);
}

bool Person::canTakeBooks() const
{
    return std::ranges::find(roles_, true, &Role::canTakeBooks) != roles_.end();
}

int Person::getMaxArendaDays() const {
    int maxDays = 0;
    for (const auto& role : roles_) 
    {
        if (role->canTakeBooks()) 
        {
            maxDays = std::max(maxDays, role->getDefaultArendaDays());
        }
    }
    return maxDays;
}

int Person::getMaxActiveArendas() const {
    int maxA = 0;
    for (const auto& role : roles_) 
    {
        if (role->canTakeBooks()) 
        {
            maxA = std::max(maxA, role->getMaxActiveArendas());
        }
    }
    return maxA;
}