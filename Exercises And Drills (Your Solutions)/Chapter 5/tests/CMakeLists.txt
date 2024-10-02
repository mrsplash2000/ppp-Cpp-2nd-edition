cmake_minimum_required(VERSION 3.11)
project(chap5)

# Set the c++ compiler to my own install version 14.1
set(CMAKE_CXX_COMPILER "/usr/bin/g++")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the Catch2 package
find_package(Catch2 3 REQUIRED)

# Create the test executable
add_executable(11test 11test.cpp ../fib.cpp)

# Link the test executable with Catch2WithMain
target_link_libraries(11test PRIVATE libCatch2Main.a libCatch2.a)
