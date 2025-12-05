#include "functions.h"

void readRawImgFromFile(std::ifstream& file,
                        std::vector<unsigned char>& imgData) {
  unsigned char component;
  while (file.read(reinterpret_cast<char*>(&component), sizeof(component))) {
    imgData.push_back(component);
  }
}

void drawDimensionsPopUp(bool& active, int& width, int& height, int& format) {
  if (active) {
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    constexpr int POPUP_WIDTH = 300;
    constexpr int POPUP_HEIGHT = 200;

    constexpr int MAX_IMAGE_DIMENSION = 8000;

    Rectangle bounds = {
        .x = static_cast<int>(screenWidth / 2.0 - POPUP_WIDTH / 2.0),
        .y = static_cast<int>(screenHeight / 2.0 - POPUP_HEIGHT / 2.0),
        .width = POPUP_WIDTH,
        .height = POPUP_HEIGHT};

    if (GuiWindowBox(bounds, "Image Dimensions")) {
      active = false;
    }

    static bool widthEditMode = false;
    static bool heightEditMode = false;
    static bool formatEditMode = false;

    if (GuiValueBox((Rectangle){bounds.x + 80, bounds.y + 40, 120, 30},
                    "Width:", &width, 1, MAX_IMAGE_DIMENSION, widthEditMode)) {
      widthEditMode = !widthEditMode;
    }

    if (GuiValueBox((Rectangle){bounds.x + 80, bounds.y + 80, 120, 30},
                    "Height:", &height, 1, MAX_IMAGE_DIMENSION,
                    heightEditMode)) {
      heightEditMode = !heightEditMode;
    }

    if (GuiButton((Rectangle){bounds.x + 100, bounds.y + 160, 100, 30},
                  "Confirm")) {
      active = false;
    }

    if (GuiDropdownBox((Rectangle){bounds.x + 80, bounds.y + 130, 120, 30},
                       "RGB;RGBA", &format, formatEditMode)) {
      formatEditMode = !formatEditMode;
    }
  }
}

Texture2D loadRawTexture(std::vector<unsigned char>& imgData, int width,
                         int height, int format) {
  int bytesPerPixel = (format == 0) ? 3 : 4;
  int pixelFormat = (format == 0) ? PIXELFORMAT_UNCOMPRESSED_R8G8B8
                                  : PIXELFORMAT_UNCOMPRESSED_R8G8B8A8;

  if (imgData.size() < (size_t)(width * height * bytesPerPixel)) {
    return (Texture2D){0};
  }

  Image img = {.data = imgData.data(),
               .width = width,
               .height = height,
               .mipmaps = 1,
               .format = pixelFormat};
  Texture2D texture = LoadTextureFromImage(img);
  return texture;
}