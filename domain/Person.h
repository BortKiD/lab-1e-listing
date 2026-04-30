#pragma once
#include <vector>
#include <memory>
#include "Role.h"
#include "Email.h"

class Person 
{
public:
    explicit Person(int id, std::string fullName, std::string email);

    int getId() const;
    const std::string& getFullName() const;
    const Email& getEmail() const;

    void addRole(std::shared_ptr<Role> role);
    bool hasRole(const std::string& roleName) const;
    void changeEmail(Email& newEmail);
    bool canTakeBooks() const;
    int getMaxArendaDays() const;
    int getMaxActiveArendas() const;

private:
    int id_;
    std::string fullName_;
    Email email_;
    std::vector<std::shared_ptr<Role>> roles_;
};
