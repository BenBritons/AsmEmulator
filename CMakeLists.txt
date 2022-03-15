cmake_minimum_required(VERSION 3.20)
project(lab_13)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(lib)
add_subdirectory(log)

include_directories(googletest/include googletest include)

add_executable(lab_13 main.cpp Command.cpp Command.h Realization.h)
target_link_libraries(lab_13 spdlog gtest gtest_main)