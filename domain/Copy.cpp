#include <stdexcept>
#include "Copy.h"

Copy::Copy(int inventoryNumber)
    : inventoryNumber_(inventoryNumber) 
{
}

bool Copy::isAvailable() const 
{
    return available_;
}

void Copy::markAsBorrowed()
{
    if (!available_) 
        throw std::logic_error("Copy is not available!");
    available_ = false;
}

void Copy::markAsReturned()
{
    if (available_) 
        throw std::logic_error("Copy is already returned!");
    available_ = true;
}