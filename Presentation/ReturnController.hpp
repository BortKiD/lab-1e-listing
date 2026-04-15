#pragma once
#include "../Application/LibraryFacade.hpp"

class ReturnController {
private:
    LibraryFacade& facade;

public:
    ReturnController(LibraryFacade& facade);

    void returnBook(int loanId);
};