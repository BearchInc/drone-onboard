cmake_minimum_required(VERSION 3.3)
project(DroneOnboard)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories("${PROJECT_SOURCE_DIR}/DJI_LIB")

file(GLOB DJI_SOURCES DJI_LIB/*.cpp)
add_library(djisdk SHARED ${DJI_SOURCES})

add_executable(DroneOnboard main.cpp)

target_link_libraries(DroneOnboard djisdk)
