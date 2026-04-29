#include "Email.h"
#include <stdexcept>
#include <regex>

static bool validateEmail(std::string value)
{
    const std::regex pattern(R"([a-z0-9]+@[a-z]+\.[a-z]{2,3})");
    return std::regex_match(value, pattern);
}

Email::Email(std::string value) 
: value_(std::move(value))
{
    if (!validateEmail(value))
        throw std::invalid_argument("Invalid email!");
}

const std::string& Email::value() const 
{
    return value_;
}
