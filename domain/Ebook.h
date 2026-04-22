#pragma once
#include "Book.h"

class EBook : public Book 
{
public:
    using Book::Book;
    std::string getDescription() const override;
};
