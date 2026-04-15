#pragma once
#include "../Domain/Book.hpp"

class BookRepository {
public:
    virtual Book findByIsbn(const std::string& isbn) = 0;
    virtual void save(const Book& book) = 0;
    virtual ~BookRepository() = default;
};