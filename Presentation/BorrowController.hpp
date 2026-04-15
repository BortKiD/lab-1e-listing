#pragma once
#include "../Application/LibraryFacade.hpp"

class BorrowController {
private:
    LibraryFacade& facade;

public:
    BorrowController(LibraryFacade& facade);

    void borrowBook(int userId, int copyId);
};