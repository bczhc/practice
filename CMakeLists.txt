SET(CMAKE_C_COMPILER clang)
SET(CMAKE_CXX_COMPILER clang++)
add_compile_options(-g)
project(practice)

add_executable(test ./test.cpp)
