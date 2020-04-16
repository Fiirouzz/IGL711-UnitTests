cmake_minimum_required(VERSION 3.12)
project(BankTest
        VERSION 1.0
        LANGUAGES C CXX
        DESCRIPTION "Final Exam Bank test")

set(CXX_STANDARD 17)

add_subdirectory(bank)
add_subdirectory(tests)

add_executable(bankUser main.cpp)
