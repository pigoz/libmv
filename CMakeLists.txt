cmake_minimum_required(VERSION 3.4)
project(libmv)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(OpenCL REQUIRED)

# includes
include_directories(${OPENCL_INCLUDE_DIR})
include_directories(include)
include_directories(src)

add_library(libmv src/mv.c src/super.c src/ta.c src/ta_utils.c)
target_link_libraries(libmv ${OpenCL_LIBRARIES})

add_executable(examples_super examples/super.c)
target_link_libraries(examples_super libmv)
