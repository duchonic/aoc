cmake_minimum_required(VERSION 3.4)
set(CMAKE_CXX_STANDARD 17)
project(aoc)
add_executable(day02 main.cpp)

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

target_link_libraries(day02 PUBLIC matplot)
