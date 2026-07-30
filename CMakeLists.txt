cmake_minimum_required(VERSION 4.4.1)

project(experimental_vulkan VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/basics/cmake")
include(Utils)

find_package(Vulkan REQUIRED COMPONENTS glslc)
find_package(glfw3 CONFIG REQUIRED)

option(BUILD_TESTS "Build unit tests" ON)
enable_testing()

add_subdirectory(basics/src/simple_shapes)

if(BUILD_TESTS)
    add_subdirectory(basics/test)
endif()
