#include <raylib.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <string>

#define RAYGUI_IMPLEMENTATION

#include "functions.h"

constexpr int DEFAULT_WIN_WIDTH = 900;
constexpr int DEFAULT_WIN_HEIGHT = 600;

int main(int argc, char** argv) {
  std::string path = "";
  int width = DEFAULT_WIN_WIDTH, height = DEFAULT_WIN_HEIGHT;

  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <path_to_raw_image_file>"
              << std::endl;
    return -1;
  }
  path = std::string(argv[1]);
  std::ifstream file;
  file.open(path);
  if (!file.good()) {
    std::cerr << "Could not open the specified file!" << std::endl;
    return -1;
  }

  std::string windowTitle = "RawImgViewer - " + path;
  InitWindow(width, height, windowTitle.c_str());
  SetTargetFPS(60);

  bool showPopUp = true;
  while (!WindowShouldClose()) {
    BeginDrawing();

    if (showPopUp) {
      drawDimensionsPopUp(showPopUp, width, height);
    } else {
      SetWindowSize(width, height);
      ClearBackground(BLACK);

      drawRawImgFromFile(file, width, height);
    }

    EndDrawing();
  }
  CloseWindow();

  file.close();
  return 0;
}