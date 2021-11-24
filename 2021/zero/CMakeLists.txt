cmake_minimum_required(VERSION 3.4)
set(CMAKE_CXX_STANDARD 17)
project(hello_world)
add_executable(app main.cpp)

add_executable(test test/main.cpp test/bitwise.cpp
	test/math.cpp
)
target_include_directories(test PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
set(url https://github.com/philsquared/Catch/releases/download/v2.13.6/catch.hpp)
file(
  DOWNLOAD ${url} "${CMAKE_CURRENT_BINARY_DIR}/catch.hpp"
  STATUS status
  EXPECTED_HASH SHA256=681e7505a50887c9085539e5135794fc8f66d8e5de28eadf13a30978627b0f47)
list(GET status 0 error)
if(error)
  message(FATAL_ERROR "Could not download ${url}")
endif()
target_include_directories(test PUBLIC "${CMAKE_CURRENT_BINARY_DIR}")
