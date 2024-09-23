cmake_minimum_required(VERSION 3.20)
set(CMAKE_CPP_COMPILER clang++)
set(CMAKE_CPP_STANDARD 17)

project(seagame)

include_directories("./seagame")

aux_source_directory("./seagame/src" SRC)

add_executable(seagame
  main.cpp
  ${SRC}
)
