cmake_minimum_required(VERSION 3.23)

set(EXECUTABLE_OUTPUT_PATH ./${CMAKE_BUILD_TYPE})

project(peg VERSION 0.1
    DESCRIPTION "Yet another 2D graphics framework"
    LANGUAGES CXX)

add_executable(peg
    src/main.cpp
)