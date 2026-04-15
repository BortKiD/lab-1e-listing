cmake_minimum_required(VERSION 3.16)

project(LibrarySystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(DOMAIN_SOURCES
    domain/Book.hpp
    domain/BookCopy.hpp
    domain/User.hpp
    domain/Loan.hpp
)

set(APPLICATION_SOURCES
    Application/LoanService.hpp
    Application/LibraryFacade.hpp
    Application/UserService.hpp
)

set(INFRASTRUCTURE_SOURCES
    Infrastructure/InMemoryUserRepository.hpp
    Infrastructure/UserRepository.hpp
    Infrastructure/BookRepository.hpp
    Infrastructure/BookCopyRepository.hpp
    Infrastructure/LoanRepository.hpp
)

set(PRESENTATION_SOURCES
    Presentation/BorrowController.hpp
    Presentation/ReturnController.hpp
    Presentation/UserController.hpp
    Presentation/AdminController.hpp
)

set(ALL_SOURCES
    ${DOMAIN_SOURCES}
    ${APPLICATION_SOURCES}
    ${INFRASTRUCTURE_SOURCES}
    ${PRESENTATION_SOURCES}
    main.cpp
)

add_executable(LibrarySystem ${ALL_SOURCES})

target_include_directories(LibrarySystem PRIVATE
    Domain
    Application
    Infrastructure
    Presentation
)


if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(LibrarySystem PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -o build/app.exe
    )
endif()