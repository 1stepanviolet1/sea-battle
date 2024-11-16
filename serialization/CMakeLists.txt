cmake_minimum_required(VERSION 3.10)

project(serialization)

add_definitions(-DSERIALIZATION_EXPORTS)

include_directories("${CMAKE_SOURCE_DIR}/nlohmann-json/include")
include_directories("${CMAKE_SOURCE_DIR}/seagame")
include_directories("${CMAKE_SOURCE_DIR}/serialization")

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_SERIALIZATION)

add_library(serialization SHARED 
  ${SRC_SERIALIZATION}
)

set_target_properties(serialization PROPERTIES
  PREFIX ""
  SUFFIX ".dll"
)

target_include_directories(serialization PUBLIC ${CMAKE_SOURCE_DIR}/serialization)

target_link_libraries(serialization PRIVATE seagame_lib)

