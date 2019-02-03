cmake_minimum_required(VERSION 3.12)
project(sort)

set(CMAKE_CXX_STANDARD 14)

# have compiler give warnings, but not for signed/unsigned
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -Wno-sign-compare")

add_executable(sort main.cpp sort_template.cpp sort_simple.cpp)