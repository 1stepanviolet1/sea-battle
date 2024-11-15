cmake_minimum_required(VERSION 3.20)

project(serialization)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("../nlohmann-json/include")
include_directories("../seagame")
include_directories(".")

aux_source_directory("./src" SRC)

add_library(serialization SHARED {SRC})

