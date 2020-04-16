add_executable(banktests
		unittests.cpp
		catch.hpp
		)


target_link_libraries(banktests
		PRIVATE
		bank
		)

target_include_directories(banktests
		PRIVATE
		bank
		)
