cmake_minimum_required(VERSION 3.4)
set(CMAKE_CXX_STANDARD 17)
project(hello_world)
add_executable(app main.cpp)


add_executable(test 
  ../../help/test/main.cpp 
  ../../help/../help/test/bitwise.cpp
  ../../help/../help/test/geometry.cpp
  ../../help/../help/test/math.cpp
  ../../help/../help/test/string.cpp
)
include_directories(
  ../../
)
include(FetchContent)
FetchContent_Declare(matplotplusplus
        GIT_REPOSITORY https://github.com/alandefreitas/matplotplusplus
        GIT_TAG origin/master # or whatever tag you want
)
FetchContent_GetProperties(matplotplusplus)
if(NOT matplotplusplus_POPULATED)
    FetchContent_Populate(matplotplusplus)
    add_subdirectory(${matplotplusplus_SOURCE_DIR} ${matplotplusplus_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

target_link_libraries(app PUBLIC matplot)

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
