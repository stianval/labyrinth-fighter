#include "port.h"
#include "utilities.h"

void drawtext(int x, int y, int color, char text[]) 
{
  SDL_Color tmpfontcolor = {255,255,255,255};
  SDL_Color tmpfontbgcolor = {0, 0, 0, 0};
  SDL_Surface *resulting_text;
 
  resulting_text = TTF_RenderText_Solid(fonttodraw, text, tmpfontcolor);
  //resulting_text = TTF_RenderText_Shaded(fonttodraw, text, tmpfontcolor, tmpfontbgcolor);
  //resulting_text = TTF_RenderText_Blended(fonttodraw, text, tmpfontcolor);
}
TTF_Font* loadfont(char* file, int ptsize) 
{
  TTF_Font* tmpfont;
  tmpfont = TTF_OpenFont(file, ptsize);
  if (tmpfont == NULL){
    printf("Unable to load font: %s %s \n", file, TTF_GetError());
    // Handle the error here.
  }
  return tmpfont;
}