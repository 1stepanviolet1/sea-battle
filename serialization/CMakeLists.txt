cmake_minimum_required(VERSION 3.10)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../nlohmann-json/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../seagame")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

file(GLOB SRC_SERIALIZATION "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(serialization SHARED 
  ${SRC_SERIALIZATION}
)

