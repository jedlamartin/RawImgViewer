#ifndef POPUP_H
#define POPUP_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "raygui.h"

void readRawImgFromFile(std::ifstream& file,
                        std::vector<unsigned char>& imgData);
void drawDimensionsPopUp(bool& active, int& width, int& height, int& format);
Texture2D loadRawTexture(std::vector<unsigned char>& imgData, int width,
                         int height, int format);

#endif  // POPUP_H