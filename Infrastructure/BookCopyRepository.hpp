#pragma once
#include "../Domain/BookCopy.hpp"

class BookCopyRepository {
public:
    virtual BookCopy findById(const int id) = 0;
    virtual void save(const BookCopy& bookCopy) = 0;
    virtual ~BookCopyRepository() = default;
};
