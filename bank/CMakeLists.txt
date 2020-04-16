add_library(
        bank
        bankUser.cpp)

target_include_directories(bank
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        )
