include_directories(includes)

file(GLOB SOURCES *.cpp)
add_library(djisdk ${SOURCES})

target_link_libraries(djisdk pthread)
