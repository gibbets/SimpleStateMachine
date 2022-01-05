include_directories(${CMAKE_HOME_DIRECTORY}/lib)

add_executable(ssm_gtest
    main.cpp
)

target_link_libraries(ssm_gtest
    GTest::GTest
)