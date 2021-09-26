cmake_minimum_required(VERSION 3.16.0)
project(led VERSION 0.1.0
            DESCRIPTION "lighting all leds in easy module pi"
            LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(${CMAKE_SOURCE_DIR}/src)

# download wiringPi as a lib
include(FetchContent)

set(WIRINGPI wiringpi)

FetchContent_Declare(
  ${WIRINGPI}
  GIT_REPOSITORY https://hub.fastgit.org/WiringPi/WiringPi.git
  GIT_TAG        7f8fe26e4f775abfced43c07657a353f03ddb2d0
)

FetchContent_MakeAvailable(WIRINGPI)

message(NOTICE "WiringPi_SOURCE_DIR: ${${WIRINGPI}_SOURCE_DIR}")

target_include_directories(led PRIVATE ${${WIRINGPI}_SOURCE_DIR}/wiringPi)
# end wiringPi
