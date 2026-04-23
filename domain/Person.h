#pragma once
#include <vector>
#include <memory>
#include "Role.h"

class Person 
{
public:
    explicit Person(int id, std::string fullName, std::string email);

    int getId() const;
    const std::string& getFullName() const;
    const std::string& getEmail() const;

    void addRole(std::shared_ptr<Role> role);
    bool hasRole(const std::string& roleName) const;
    void changeEmail(const std::string& newEmail);
    bool canTakeBooks() const;
private:
    int id_;
    std::string fullName_;
    std::string email_;
    std::vector<std::shared_ptr<Role>> roles_;
};
