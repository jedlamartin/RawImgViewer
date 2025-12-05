cmake_minimum_required(VERSION 3.10.0)
project(RawImgViewer VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(raylib REQUIRED)
add_executable(RawImgViewer main.cpp)
target_link_libraries(RawImgViewer PRIVATE raylib)
add_compile_options(-Wall -Wextra -Wpedantic)

