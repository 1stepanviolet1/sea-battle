cmake_minimum_required(VERSION 3.20)

project(seagame VERSION 3.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(utils)
add_subdirectory(seagame)
add_subdirectory(serialization)

include_directories("${CMAKE_SOURCE_DIR}/nlohmann-json/include")

add_executable(seagame main.cpp)

target_link_libraries(seagame PRIVATE seagame_lib)
target_link_libraries(seagame PRIVATE utils)

