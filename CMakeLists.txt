cmake_minimum_required(VERSION 3.10.0)
project(RawImgViewer VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG master
)
FetchContent_MakeAvailable(raylib)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c")

add_executable(RawImgViewer ${SOURCES})

target_link_libraries(RawImgViewer PRIVATE raylib)
target_include_directories(RawImgViewer PRIVATE include)

add_compile_options(-Wextra -Wpedantic)

install(TARGETS RawImgViewer DESTINATION bin)