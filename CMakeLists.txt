cmake_minimum_required(VERSION 3.27)
project(JsonValidator)

set(CMAKE_CXX_STANDARD 14)

add_executable(JsonValidator
        main.cpp
        Lexer.cpp
        Parser.cpp
        utilities.cpp)
