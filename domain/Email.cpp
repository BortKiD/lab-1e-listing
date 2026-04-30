#include "Email.h"
#include <stdexcept>
#include <regex>

static bool validateEmail(std::string value)
{
    const std::regex pattern(R"([a-z0-9]+@[a-z]+\.[a-z]{2,3})", std::regex::icase);
    return std::regex_match(value, pattern);
}

Email::Email(std::string value)
{
    if (!validateEmail(value))
        throw std::invalid_argument("Invalid email!");

    value_ = std::move(value);
}

const std::string& Email::value() const 
{
    return value_;
}
