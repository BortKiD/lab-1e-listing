#pragma once
#include <string>

class Role 
{
public:
    virtual ~Role() = default;
    virtual std::string getName() const = 0;
    virtual bool canTakeBooks() const;
    virtual int getDefaultArendaDays() const = 0;
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

    int getDefaultArendaDays() const override
    {
        return 100;
    }
};

class LibrarianRole : public Role 
{
public:
    std::string getName() const override 
    {
        return "Librarian";
    }

    int getDefaultArendaDays() const override
    {
        return 180;
    }
};

class AdminRole : public Role 
{
public:
    std::string getName() const override 
    {
        return "Admin";
    }

    int getDefaultArendaDays() const override
    {
        return 180;
    }
};

class GuestRole : public Role 
{
public:
    std::string getName() const override 
    {
        return "Guest";
    }

    int getDefaultArendaDays() const override
    {
        return 30;
    }
};