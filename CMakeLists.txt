cmake_minimum_required(VERSION 3.23)

set(EXECUTABLE_OUTPUT_PATH ./${CMAKE_BUILD_TYPE})

project(peg VERSION 0.1
    DESCRIPTION "Yet another 2D graphics framework"
    LANGUAGES CXX)

find_package(glfw REQUIRED)

add_executable(peg
    src/main.cpp
)

target_include_directories(peg
    PUBLIC
    ${GLFW_INCLUDE_DIRS}
)

target_link_directories(peg
    PUBLIC
    ${GLFW_LIBRARIES}
)

target_link_libraries(peg
    glfw3
    opengl32
)