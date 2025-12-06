#include <raylib.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define RAYGUI_IMPLEMENTATION

#include "functions.h"

constexpr int DEFAULT_WIN_WIDTH = 900;
constexpr int DEFAULT_WIN_HEIGHT = 600;
constexpr int DEFAULT_FORMAT = 0;  // 0 for RGB, 1 for RGBA

int main(int argc, char** argv) {
  std::string path = "";
  int width = DEFAULT_WIN_WIDTH, height = DEFAULT_WIN_HEIGHT;
  int format = DEFAULT_FORMAT;

  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <path_to_raw_image_file>"
              << std::endl;
    return -1;
  }
  path = std::string(argv[1]);
  std::ifstream file;
  file.open(path, std::ios::binary);
  if (!file.good()) {
    std::cerr << "Could not open the specified file!" << std::endl;
    return -1;
  }

  std::vector<unsigned char> imgData;
  readRawImgFromFile(file, imgData);
  file.close();

  std::string windowTitle = "RawImgViewer - " + path;
  InitWindow(width, height, windowTitle.c_str());
  SetTargetFPS(60);

  bool showPopUp = true;
  Texture2D texture = {0};
  bool textureLoaded = false;

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);  // Always clear background first

    if (showPopUp) {
      drawDimensionsPopUp(showPopUp, width, height, format);
    } else {
      if (!textureLoaded) {
        texture = loadRawTexture(imgData, width, height, format);
        SetWindowSize(width, height);
        textureLoaded = true;
      }

      DrawTexture(texture, 0, 0, WHITE);
    }

    EndDrawing();
  }

  if (textureLoaded) {
    UnloadTexture(texture);
  }
  CloseWindow();

  return 0;
}
