cmake_minimum_required(VERSION 3.10)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../serialization")

file(GLOB SRC_SEAGAME "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(seagame
  main.cpp
  ${SRC_SEAGAME}
)

