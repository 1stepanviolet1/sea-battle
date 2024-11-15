
include_directories("../../nlohmann-json/include")
include_directories("..")

aux_source_directory("./src" SRC)

add_library(serialization SHARED {SRC})

