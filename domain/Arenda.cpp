#include "Arenda.h"
#include "Person.h"
#include "Copy.h"
#include <chrono>
#include <stdexcept>

Arenda::Arenda(
    std::shared_ptr<Person> person, 
    std::shared_ptr<Copy> copy)
    :
    person_(person),
    copy_(copy),
    startDate_(std::chrono::system_clock::now()),
    status_(ArendaStatus::Active)
{
    if (!person_) 
        throw std::invalid_argument("Person cannot be null!");
    if (!copy_) 
        throw std::invalid_argument("Copy cannot be null!");
}

std::shared_ptr<Person> Arenda::getPerson() const 
{    
    return person_;
}

std::shared_ptr<Copy> Arenda::getCopy() const
{    
    return copy_;
}

std::chrono::system_clock::time_point Arenda::getEndDate() const 
{
    return endDate_;
}

bool Arenda::isActive() const
{
    return status_ == ArendaStatus::Active;
}

void Arenda::close()
{
    if (status_ == ArendaStatus::Closed) 
    {
        throw std::logic_error("Loan is already closed!");
    }
    status_ = ArendaStatus::Closed;
    endDate_ = std::chrono::system_clock::now();
}
