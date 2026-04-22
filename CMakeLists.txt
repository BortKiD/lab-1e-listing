cmake_minimum_required(VERSION 3.16)

project(LibrarySystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(DOMAIN_SOURCES
    domain/Book.h
    domain/Book.cpp
    domain/Arenda.h
    domain/Arenda.cpp
    domain/Person.h
    domain/Person.cpp
    domain/Role.h
    domain/Role.cpp
)

set(APPLICATION_SOURCES
    application/ArendaService.h
    application/ArendaService.cpp
    application/CatalogService.h
    application/CatalogService.cpp
)

set(INFRASTRUCTURE_SOURCES
    infrastructure/InMemoryArendaRepository.h
    infrastructure/InMemoryArendaRepository.cpp
    infrastructure/ArendaRepository.h
    infrastructure/ArendaRepository.cpp
)

set(ALL_SOURCES
    ${DOMAIN_SOURCES}
    ${APPLICATION_SOURCES}
    ${INFRASTRUCTURE_SOURCES}
    main.cpp
)

add_executable(LibrarySystem ${ALL_SOURCES})

target_include_directories(LibrarySystem PRIVATE
    domain
    application
    infrastructure
)


if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(LibrarySystem PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -o build/app.exe
    )
endif()