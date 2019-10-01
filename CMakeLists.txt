cmake_minimum_required(VERSION 3.1)

project (sketch_builder_server)

file(GLOB SRC_ "src/*.cpp")

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin/server")

set(CMAKE_CXX_FLAGS "-Wall -O2 -g -pthread")

add_executable(server ${SRC_})

target_include_directories(server PRIVATE "${PROJECT_SOURCE_DIR}/include")
