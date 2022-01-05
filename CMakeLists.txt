cmake_minimum_required(VERSION 3.10)

# set the project name
project(SimpleStateMachine)

find_package(GTest REQUIRED)

add_subdirectory(doc)
add_subdirectory(lib)
add_subdirectory(test)