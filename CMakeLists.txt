cmake_minimum_required(VERSION 3.16.0)
project(led VERSION 0.1.0
            DESCRIPTION "lighting all leds in easy module pi"
            LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# set bin prosition
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(${CMAKE_SOURCE_DIR}/src)

find_library(wiringPi)
target_link_libraries(led SHARE wiringPi)
