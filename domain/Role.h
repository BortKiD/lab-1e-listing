#pragma once
#include <string>

class Role 
{
public:
    virtual ~Role() = default;
    virtual std::string getName() const = 0;
    virtual bool canTakeBooks() const;
};

class ReaderRole : public Role 
{
public:
    std::string getName() const override 
    {
        return "Reader";
    }

    bool canTakeBooks() const override 
    {
        return true;
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

class GuestRole : public Role 
{
public:
    std::string getName() const override 
    {
        return "Guest";
    }
};