cmake_minimum_required(VERSION 3.4)
set(CMAKE_CXX_STANDARD 17)
project(hello_world)
add_executable(app main.cpp)

include_directories(
  ../../
)
