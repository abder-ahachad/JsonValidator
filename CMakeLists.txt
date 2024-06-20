cmake_minimum_required(VERSION 3.17)
project(JsonValidator)

set(CMAKE_CXX_STANDARD 14)

add_executable(JsonValidator
        main.cpp
        src/Lexer.cpp
        src/Parser.cpp
        src/utilities.cpp)
