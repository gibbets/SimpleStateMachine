include_directories(${CMAKE_HOME_DIRECTORY}/lib)

enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(tests main.cpp)
target_link_libraries(tests GTest::GTest GTest::Main)
gtest_discover_tests(tests)