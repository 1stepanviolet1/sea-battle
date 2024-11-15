
include_directories("../../nlohmann-json/include")
include_directories("..")

aux_source_directory("." SRC)

add_library(serialization SHARED {SRC})

