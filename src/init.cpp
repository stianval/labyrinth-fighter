#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <GL/gl.h>

#include "init.h"

int init(void)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	
	SDL_SetVideoMode(1024,768, 0, SDL_OPENGL);
	
	SDL_WM_SetCaption( "Labyrinth Fighter /o/", NULL );
	
	glClearColor( 1,0,0,0);
	
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	//glOrtho( 0,0,1024, 768, 10, -10);
	gluPerspective( 75.0, 1024.0/768.0, 0.1, 1000.0 );
	
	return 0;
}
