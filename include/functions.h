#ifndef POPUP_H
#define POPUP_H

#include <fstream>
#include <iostream>
#include <string>

#include "raygui.h"

void drawDimensionsPopUp(bool& active, int& width, int& height);
void drawRawImgFromFile(std::ifstream& file, int width, int height);

#endif  // POPUP_H