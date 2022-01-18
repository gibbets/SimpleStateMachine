cmake_minimum_required(VERSION 3.10)

# set the project name
project(SimpleStateMachine)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(GTest REQUIRED)
find_package(GMock REQUIRED)

include(clang-format)

add_subdirectory(doc)
add_subdirectory(lib)
add_subdirectory(test)