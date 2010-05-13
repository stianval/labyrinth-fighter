#include "port.h"
#include "utilities.h"
TTF_Font *fontToDraw;

void drawtext(int x, int y, int color, char text[]) 
{
  SDL_Color tmpfontcolor = {0,255,255,0};
  //SDL_Color tmpfontbgcolor = {0, 0, 0, 0};
  SDL_Surface *resulting_text;
 
  SDL_Rect dest = {x, y,255, 255};

  resulting_text = TTF_RenderText_Solid(fontToDraw, text, tmpfontcolor);
  SDL_BlitSurface(resulting_text, NULL, SDL_GetVideoSurface(), &dest);

  SDL_FreeSurface(resulting_text);
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