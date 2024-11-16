cmake_minimum_required(VERSION 3.10)

project(seagame_lib)

include_directories("${CMAKE_SOURCE_DIR}/seagame")

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_SEAGAME)

add_library(seagame_lib STATIC 
  ${SRC_SEAGAME}
)

set_target_properties(seagame_lib PROPERTIES
  PREFIX ""
  SUFFIX ".lib"
)

target_include_directories(seagame_lib PUBLIC ${CMAKE_SOURCE_DIR}/seagame)

