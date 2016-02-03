include_directories(includes)

file(GLOB SOURCES *.cpp)
add_library(core ${SOURCES})

target_link_libraries(core djisdk DJI_guidance usb-1.0 rt wiringPi wiringPiDev)
