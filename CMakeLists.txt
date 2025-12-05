cmake_minimum_required(VERSION 3.10.0)
project(RawImgViewer VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c")

find_package(raylib REQUIRED)
add_executable(RawImgViewer ${SOURCES})
target_link_libraries(RawImgViewer PRIVATE raylib)
target_include_directories(RawImgViewer PRIVATE include)
add_compile_options(-Wextra -Wpedantic)

