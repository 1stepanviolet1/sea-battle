cmake_minimum_required(VERSION 3.20)

project(seagame VERSION 3.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(seagame)
add_subdirectory(serialization)

add_executable(seagame main.cpp)

target_link_libraries(seagame PRIVATE seagame_lib)

