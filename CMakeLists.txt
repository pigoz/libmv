cmake_minimum_required(VERSION 3.4)
project(libmv)

enable_testing()
set(CMAKE_C_FLAGS "-Wall -Werror -Wpedantic -std=c11")
set(CMAKE_INCLUDE_CURRENT_DIR on)
find_package(OpenCL REQUIRED)

include_directories(${OPENCL_INCLUDE_DIR})
include_directories(include)

add_subdirectory(src)
add_subdirectory(examples)
# add_subdirectory(test)
