cmake_minimum_required(VERSION 3.28)
project(cpp_championship_2)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE my_src source/*.cpp)
add_executable(cpp_championship_2 ${my_src})