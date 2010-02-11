#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

#include "init.h"

int init(void)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	
	SDL_Surface *draw;
	draw = SDL_SetVideoMode(1024,768, 0, SDL_OPENGL);
}
