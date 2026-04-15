#pragma once
#include <string>

class Book {
private:
    std::string isbn;
    std::string title;
    std::string author;

public:
    Book(std::string isbn, std::string title, std::string author);
    
    std::string getIsbn() const;
    std::string getTitle() const;
    std::string getAuthor() const;
};
