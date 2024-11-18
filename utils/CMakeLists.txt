cmake_minimum_required(VERSION 3.20)

project(utils)

include_directories("${CMAKE_SOURCE_DIR}/utils")
include_directories("${CMAKE_SOURCE_DIR}/nlohmann-json/include")

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_UTILS)

add_library(utils STATIC 
  ${SRC_UTILS}
)

set_target_properties(utils PROPERTIES
  PREFIX ""
  SUFFIX ".lib"
)

target_include_directories(utils PUBLIC ${CMAKE_SOURCE_DIR}/utils)

