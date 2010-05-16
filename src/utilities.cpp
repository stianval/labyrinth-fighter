#include "port.h"
#include "utilities.h"
#include "debug.h"
TTF_Font *fontToDraw;

void drawtext(int x, int y, int color, char text[]) 
{
  SDL_Color tmpfontcolor = {255,255,255,255};
  //SDL_Color tmpfontbgcolor = {0, 0, 0, 0};
  SDL_Surface *message;
 
  //SDL_Rect dest = {x, y,255, 255};

  message = TTF_RenderText_Solid(fontToDraw, text, tmpfontcolor);
  //SDL_BlitSurface(resulting_text, NULL, SDL_GetVideoSurface(), &dest);


  //Following will (probably) work with gl version 1.4 or later 
  //glWindowPos2i(0,0);

  int smiley[] = {
      0x00000000, 0xCFFFFFFF, 0xCFFFFFFF, 0xCFFFFFFF, 0xCFFFFFFF, 0xCFFFFFFF, 0xCFFFFFFF, 0x00000000,
      0xCFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xCFFFFFFF,
      0xCFFFFFFF, 0x00000000, 0x00000000, 0xCFFFFFFF, 0xCFFFFFFF, 0x00000000, 0x00000000, 0xCFFFFFFF,
      0xCFFFFFFF, 0x00000000, 0xCFFFFFFF, 0x00000000, 0x00000000, 0xCFFFFFFF, 0x00000000, 0xCFFFFFFF,
      0xCFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xCFFFFFFF,
      0xCFFFFFFF, 0x00000000, 0xCFFFFFFF, 0x00000000, 0x00000000, 0xCFFFFFFF, 0x00000000, 0xCFFFFFFF,
      0xCFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xCFFFFFFF,
      0x00000000, 0xCFFFFFFF, 0xCFFFFFFF, 0xCFFFFFFF, 0xCFFFFFFF, 0xCFFFFFFF, 0xCFFFFFFF, 0x00000000
  };

  glPixelZoom(10,10);

  // Displays the smiley.
  glDrawPixels(8, 8, GL_RGBA, GL_UNSIGNED_BYTE, (void*)smiley);

  // Wont work. It's slow and will only display a black rectangle
  //glDrawPixels(message->w, message->h, GL_RED, GL_BYTE, message->pixels);

  //PRINTV(glGetError());

  SDL_FreeSurface(message);
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