cmake_minimum_required(VERSION 3.4)
set(CMAKE_CXX_STANDARD 20)
project(aoc)
# use cpp 20
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
add_subdirectory(2023/day01)
add_subdirectory(2023/day02)
add_subdirectory(2023/day03)
add_subdirectory(2023/day04)
add_subdirectory(2023/day05)
add_subdirectory(2023/day06)
add_subdirectory(2023/day07)
add_subdirectory(2023/day08)
add_subdirectory(2023/day11)
add_subdirectory(2023/day14)

add_executable(test 
  ../help/test/main.cpp 
  ../help/test/bitwise.cpp
  ../help/test/geometry.cpp
  ../help/test/math.cpp
  ../help/test/string.cpp
)
include_directories(
 . 
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
