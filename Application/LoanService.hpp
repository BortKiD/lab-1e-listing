#pragma once
#include "../Infrastructure/LoanRepository.hpp"
#include "../Infrastructure/UserRepository.hpp"
#include "../Infrastructure/BookRepository.hpp"

class LoanService {
private:
    LoanRepository& loanRepo;
    UserRepository& userRepo;
    BookRepository& bookRepo;

public:
    LoanService(LoanRepository& l, UserRepository& u, BookRepository& b);

    void borrowBook(int userId, int copyId);
    void returnBook(int loanId);
};