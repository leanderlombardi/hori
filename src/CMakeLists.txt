cmake_minimum_required(VERSION 3.24)
project(hori)

set(CMAKE_CXX_STANDARD 17)

add_executable(hori lexer.hpp parser.hpp ast.hpp)
