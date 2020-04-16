add_executable(tests 
    unittests.cpp
	catch.hpp
)


target_link_libraries(tests
    PRIVATE
    examfinal
)

target_include_directories(tests
    PRIVATE
    examfinal
)