# TODO
# Make sure we can run on linux

cmake_minimum_required(VERSION 3.3)
project(DroneOnboard)

set(CMAKE_CXX_COMPILER "/usr/local/linaro/arm-linux-gnueabihf-raspbian/bin/arm-linux-gnueabihf-g++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Glob Source Files
file(GLOB DJI_SOURCES libs/DJI_LIB/*.cpp)
file(GLOB SOURCES src/*.cpp)

# Header Search Paths
include_directories("libs/DJI_LIB")
include_directories("${PROJECT_SOURCE_DIR}/libs/includes")

# Shared Libraries Sources
add_library(djisdk ${DJI_SOURCES})

# Library Search Paths
link_directories("${PROJECT_SOURCE_DIR}/libs")

# Build Executable and Link Libraries
add_executable(DroneOnboard ${SOURCES})
target_link_libraries(DroneOnboard djisdk rt pthread DJI_guidance usb-1.0 wiringPi wiringPiDev)
