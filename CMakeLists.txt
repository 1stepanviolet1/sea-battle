cmake_minimum_required(VERSION 3.20)

project(seagame)

set(CMAKE_CPP_COMPILER clang++)
set(CMAKE_CPP_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("./seagame")

aux_source_directory("./seagame/src" SRC)

add_executable(seagame
  main.cpp
  ${SRC}
)

