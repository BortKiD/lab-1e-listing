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
    int days = person->getMaxArendaDays();
    if (!person_->canTakeBooks() || days <= 0)
        throw std::logic_error("This person cannot take books!");
    if (!copy_) 
        throw std::invalid_argument("Copy cannot be null!");
    if (!copy_->isAvailable())
        throw std::invalid_argument("Copy is already borrowed!");
    
    dueDate_ = startDate_ + std::chrono::hours(24 * days);

    copy_->markAsBorrowed();
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
    copy_->markAsReturned();
}

bool Arenda::isOverdue() const {
    bool res;
    if (status_ == ArendaStatus::Closed) { res = false; }
    else
    {
        res = std::chrono::system_clock::now() > dueDate_;
    }
    return res;
}