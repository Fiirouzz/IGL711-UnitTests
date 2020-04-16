cmake_minimum_required(VERSION 3.12)
project(GitUS
    VERSION 1.0
    LANGUAGES C CXX
    DESCRIPTION "Exam final")
		
set(CXX_STANDARD 17)

add_subdirectory(examfinal)
add_subdirectory(tests)

add_executable(examfinal Modules.cpp)

target_link_libraries(examfinal
    PRIVATE
        examfinal
)
