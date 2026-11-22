cmake_minimum_required(VERSION 3.20)
project(CW15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_executable(test_ratio test_ratio.cpp Ratio.cpp)
add_executable(test_point test_point.cpp Point.cpp)
add_executable(test_poly test_poly.cpp Poly.cpp)

add_test(NAME test_ratio COMMAND test_ratio)
add_test(NAME test_point COMMAND test_point)
add_test(NAME test_poly COMMAND test_poly)

