#include "Ebook.h"

std::string EBook::getDescription() const
{
    return Book::getDescription() + " [E-Book]";
}
