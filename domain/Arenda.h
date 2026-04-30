#pragma once
#include <memory>
#include <chrono>

enum ArendaStatus
{
    Active,
    Closed
};

class Person;

class Copy;

class Arenda 
{
public:
    Arenda(std::shared_ptr<Person> person,
           std::shared_ptr<Copy> copy);
    std::shared_ptr<Person> getPerson() const;
    std::shared_ptr<Copy> getCopy() const;
    bool isActive() const;
    bool isOverdue() const;
    std::chrono::system_clock::time_point getEndDate() const;
    void close();

private:
    std::shared_ptr<Person> person_;
    std::shared_ptr<Copy> copy_;
    std::chrono::system_clock::time_point startDate_;
    std::chrono::system_clock::time_point dueDate_;
    std::chrono::system_clock::time_point endDate_;
    ArendaStatus status_;
};
