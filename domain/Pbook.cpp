#include "Pbook.h"

std::string PBook::getDescription() const
{
    return Book::getDescription() + " [P-Book]";
}
