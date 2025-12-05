#include "functions.h"

void drawDimensionsPopUp(bool& active, int& width, int& height) {
  if (active) {
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    constexpr int POPUP_WIDTH = 300;
    constexpr int POPUP_HEIGHT = 200;

    Rectangle bounds = {
        .x = static_cast<int>(screenWidth / 2.0) - POPUP_WIDTH / 2.0,
        .y = static_cast<int>(screenHeight / 2.0) - POPUP_HEIGHT / 2.0,
        .width = POPUP_WIDTH,
        .height = POPUP_HEIGHT};

    if (GuiWindowBox(bounds, "Image Dimensions")) {
      active = false;
    }

    static bool widthEditMode = false;
    static bool heightEditMode = false;

    if (GuiValueBox((Rectangle){bounds.x + 80, bounds.y + 40, 120, 30},
                    "Width:", &width, 1, 8000, widthEditMode)) {
      widthEditMode = !widthEditMode;
    }

    if (GuiValueBox((Rectangle){bounds.x + 80, bounds.y + 80, 120, 30},
                    "Height:", &height, 1, 8000, heightEditMode)) {
      heightEditMode = !heightEditMode;
    }

    if (GuiButton((Rectangle){bounds.x + 100, bounds.y + 160, 100, 30},
                  "Confirm")) {
      active = false;
    }
  }
}

void drawRawImgFromFile(std::ifstream& file, int width, int height) {
  for (int x = 0; x < width; ++x) {
    for (int y = 0; y < height; ++y) {
      unsigned char r, g, b;
      file >> r >> g >> b;
      Color color = {.r = r, .g = g, .b = b, .a = 255};
      DrawPixel(x, y, color);
    }
  }
}