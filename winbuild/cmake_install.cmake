# Install script for directory: W:/work/hack/aoc

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/aoc")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("W:/work/hack/aoc/winbuild/2021/day01/cmake_install.cmake")
  include("W:/work/hack/aoc/winbuild/2021/day03/cmake_install.cmake")
  include("W:/work/hack/aoc/winbuild/2021/day04/cmake_install.cmake")
  include("W:/work/hack/aoc/winbuild/2021/day05/cmake_install.cmake")
  include("W:/work/hack/aoc/winbuild/2021/day06/cmake_install.cmake")
  include("W:/work/hack/aoc/winbuild/2021/day07/cmake_install.cmake")
  include("W:/work/hack/aoc/winbuild/2021/day08/cmake_install.cmake")
  include("W:/work/hack/aoc/winbuild/2021/day09/cmake_install.cmake")
  include("W:/work/hack/aoc/winbuild/2021/day10/cmake_install.cmake")
  include("W:/work/hack/aoc/winbuild/2021/day11/cmake_install.cmake")
  include("W:/work/hack/aoc/winbuild/2021/day12/cmake_install.cmake")
  include("W:/work/hack/aoc/winbuild/2021/day13/cmake_install.cmake")
  include("W:/work/hack/aoc/winbuild/2021/day14/cmake_install.cmake")
  include("W:/work/hack/aoc/winbuild/2021/day15/cmake_install.cmake")
  include("W:/work/hack/aoc/winbuild/2021/day16/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "W:/work/hack/aoc/winbuild/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
