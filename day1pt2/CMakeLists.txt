cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB MY_FILES "*.txt")
file(COPY ${MY_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

project(day1pt2 VERSION 1.0)
add_executable(day1pt2 main.cpp)
