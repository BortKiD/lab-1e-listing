#include "isbn.h"
#include <stdexcept>
#include <utility>

ISBN::ISBN(std::string value)
    : value_(std::move(value)) 
{
    if (value_.empty() || value_.length() < 10)
        throw std::invalid_argument("Invalid ISBN");
}

const std::string& ISBN::value() const 
{
    return value_;
}
