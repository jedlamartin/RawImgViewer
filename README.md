# RawImgViewer

A lightweight, high-performance viewer for raw binary image files. Built with C++ and [raylib](https://www.raylib.com/).

**RawImgViewer** is designed to inspect raw pixel data (RGB or RGBA) that lacks standard headers (like BMP or PNG). It allows you to manually specify dimensions and pixel formats to visualize raw memory dumps or texture data.

## Building & Running

This project is built from source. You will need **CMake**, a **C++ Compiler**, and **Git**. You also need the system development libraries required by Raylib (X11, OpenGL, etc.).

### 1. Install Dependencies

**Ubuntu/Debian:**
```bash
sudo apt update
sudo apt install build-essential git cmake libasound2-dev mesa-common-dev libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev
```
### 2. Clone and Build

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/YOUR_USERNAME/RawImgViewer.git](https://github.com/jedlamartin/RawImgViewer.git))
    cd RawImgViewer
    ```

2.  **Create a build directory:**
    ```bash
    mkdir build
    cd build
    ```

3.  **Configure and Compile:**
    *CMake will automatically download and compile Raylib for you.*
    ```bash
    cmake ..
    cmake --build .
    ```

## Run the Application

The executable is located in the `build` folder. Run it by passing your raw image file as an argument:

```bash
./RawImgViewer path_to_your_image.raw
```
