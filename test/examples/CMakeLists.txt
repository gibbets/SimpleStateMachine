include_directories(${CMAKE_HOME_DIRECTORY}/lib)

set(CMAKE_CXX_CLANG_TIDY 
  clang-tidy;
  -header-filter=.;
  -checks=*,-llvm-header-guard,-modernize-use-trailing-return-type;)

add_executable(basic_statemachine
    basic_statemachine.cpp
)