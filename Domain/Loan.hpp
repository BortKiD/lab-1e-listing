#pragma once
#include "User.hpp"
#include "BookCopy.hpp"

class Loan {
private:
    int id;
    User user;
    BookCopy copy;
    bool isReturned;

public:
    Loan(int id, User user, BookCopy copy);

    void markReturned();
    bool getStatus() const;
};
