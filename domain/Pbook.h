#pragma once
#include "Book.h"

class PBook : public Book 
{
public:
    using Book::Book;
    std::string getDescription() const override;
};
