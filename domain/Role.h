#pragma once
#include <string>

class Role 
{
public:
    virtual ~Role() = default;
    virtual std::string getName() const = 0;
};

class ReaderRole : public Role 
{
public:
    std::string getName() const override 
    {
        return "Reader";
    }
};

class LibrarianRole : public Role 
{
public:
    std::string getName() const override 
    {
        return "Librarian";
    }
};

class AdminRole : public Role 
{
public:
    std::string getName() const override 
    {
        return "Admin";
    }
};