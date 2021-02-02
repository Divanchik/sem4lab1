cmake_minimum_required(VERSION 3.0)
project(four_sorts)

add_library(mysorts mysorts.cpp)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} mysorts)