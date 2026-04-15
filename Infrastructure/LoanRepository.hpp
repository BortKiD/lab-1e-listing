#pragma once
#include "../Domain/Loan.hpp"
#include <vector>

class LoanRepository {
public:
    virtual Loan findById(int id) = 0;
    virtual std::vector<Loan> findByUser(int userId) = 0;
    virtual void save(const Loan& loan) = 0;
    virtual ~LoanRepository() = default;
};