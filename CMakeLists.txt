cmake_minimum_required(VERSION 3.26)

set(This SWE-PROJECT-1)

project(${This} CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(HEADER_SET
    ##Fridge.h
    Ingredient.h
    ##Recipe.h
)

set(Sources
    test.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(unittest)