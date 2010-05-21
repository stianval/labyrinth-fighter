#ifndef UTILITIES_H
#define UTILITIES_H

#include "port.h"

//extern TTF_Font *fontToDraw;

void drawtext(int x, int y, int color, char text[]);
TTF_Font* loadfont(char* file, int ptsize);
#endif