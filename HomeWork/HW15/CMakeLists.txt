cmake_minimum_required(VERSION 3.28)
project(HW15 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Rectangle Rectangle.cpp Rectangle.h)

add_executable(Rectangle_test Rectangle_test.cpp)
target_link_libraries(Rectangle_test PRIVATE Rectangle)
