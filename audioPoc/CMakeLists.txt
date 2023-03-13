cmake_minimum_required(VERSION 3.0)

project(RecordAndPlay)

set(CMAKE_C_STANDARD 99)

find_package(Portaudio REQUIRED)

set(SOURCES main.c)

add_executable(RecordAndPlay ${SOURCES})

target_link_libraries(RecordAndPlay Portaudio::Portaudio)