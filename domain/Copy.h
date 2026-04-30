#pragma once
#include <memory>

class Book;

class Copy {
public:
    Copy(int inventoryNumber, std::shared_ptr<Book> book);
    bool isAvailable() const;
    void markAsBorrowed();
    void markAsReturned();
    std::shared_ptr<Book> getBook() const;
private:
    int inventoryNumber_;
    std::shared_ptr<Book> book_;
    bool available_ = true;
};