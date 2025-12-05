#include <raylib.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char** argv) {
  std::string path;
  int width = 0, height = 0;

  int opt;
  while ((opt = getopt(argc, argv, "f:w:h:")) != -1) {
    switch (opt) {
      case 'f':
        path = std::string(optarg);
        if (path.empty() || path.rfind(".raw") != path.length() - 4) {
          std::cerr << "Can only process .raw files!" << std::endl;
          return -1;
        }
        break;

      case 'w':
        width = std::stoi(optarg);
        if (width <= 0) {
          std::cerr << "Width cannot be negative or null!" << std::endl;
          return -1;
        }
        break;

      case 'h':
        height = std::stoi(optarg);
        if (height <= 0) {
          std::cerr << "Height cannot be negative or null!" << std::endl;
          return -1;
        }
        break;

      default:
        break;
    }
  }

  std::ifstream file;
  file.open(path);
  if (!file.good()) {
    std::cerr << "Could not open the specified file!" << std::endl;
    return -1;
  }

  InitWindow(width, height, "RawImgViewer");
  SetTargetFPS(60);

  for (int x = 0; x < width; ++x) {
    for (int y = 0; y < height; ++y) {
      unsigned char r, g, b;
      file >> r >> g >> b;
      Color color = {.r = r, .g = g, .b = b, .a = 255};
      DrawPixel(x, y, color);
    }
  }

  file.close();

  while (!WindowShouldClose()) {
    BeginDrawing();
    EndDrawing();
  }
  CloseWindow();
  return 0;
}