include_directories(${CMAKE_HOME_DIRECTORY}/lib)

enable_testing()
find_package(GTest REQUIRED)
find_package(GMock REQUIRED)
include(GoogleTest)

add_executable(tests main.cpp)
target_link_libraries(tests GTest::GTest GTest::Main ${GMOCK_BOTH_LIBRARIES})
gtest_discover_tests(tests)