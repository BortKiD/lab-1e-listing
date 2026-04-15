#pragma once
#include "Book.hpp"
#include "BookStatus.hpp"

class BookCopy {
private:
    int id;
    Book book;
    std::string shelfLocation;
    BookStatus status;

public:
    BookCopy(int id, Book book, std::string location);

    int getId() const;
    Book getBook() const;
    BookStatus getStatus() const;

    void markBorrowed();
    void markAvailable();
};
