#include <stdexcept>
#include <ctime>
#include <algorithm>
#include "Book.h"

static int currentYear() {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    return now->tm_year + 1900;
}

Book::Book(std::string title, ISBN isbn,
        std::vector<std::string> authors, int publicationYear) 
: title_(std::move(title)), 
isbn_(std::move(isbn)),
authors_(std::move(authors)),
publicationYear_(publicationYear) 
{
    if (isbn_.value().empty())
        throw std::invalid_argument("ISBN is empty");
    if (authors_.empty())
        throw std::invalid_argument("Authors list is empty");
    if (publicationYear_ > currentYear())
        throw std::invalid_argument("Publication year is invalid");
}

const std::string& Book::getTitle() const 
{
    return title_;
}

const ISBN Book::getIsbn() const 
{
    return isbn_;
}

const std::vector<std::string>& Book::getAuthors() const 
{
    return authors_;
}

int Book::getPublicationYear() const 
{
    return publicationYear_;
}

bool Book::check_authorship(const std::string& author) const
{
    return std::ranges::find(authors_, author) != authors_.end();
}

std::string Book::getDescription() const 
{
    return title_ + " (" + std::to_string(publicationYear_) + ")";
}
