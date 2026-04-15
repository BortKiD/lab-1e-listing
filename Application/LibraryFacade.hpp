#pragma once
#include "LoanService.hpp"

class LibraryFacade {
private:
    LoanService& loanService;

public:
    LibraryFacade(LoanService& service);

    void borrowBook(int userId, int copyId);
    void returnBook(int loanId);
};