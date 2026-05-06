#include "isbn.h"
#include <stdexcept>
#include <utility>
#include <regex>

static bool validateValue(std::string value) 
{
    const std::regex pattern(R"(ISBN [0-9]{3}-[0-9]-[0-9]{5}-[0-9]{3}-[0-9])");
    const std::regex pattern_old(R"(ISBN [0-9]-[0-9]{3}-[0-9]{5}-[0-9])");

    return std::regex_match(value, pattern) 
        || std::regex_match(value, pattern_old);
}

ISBN::ISBN(std::string value)
    : value_(std::move(value)) 
{
    if (value_.empty() || !validateValue(value_))
        throw std::invalid_argument("Invalid ISBN");
}

const std::string& ISBN::value() const 
{
    return value_;
}
