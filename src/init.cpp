#include <cstdlib>
#include <ctime>
#include "port.h"
#include "init.h"
#include "maze.h"
#include "SDL_TTF.h"

int init(void)
{
	srand(time(NULL));
	SDL_Init(SDL_INIT_EVERYTHING);
	
	SDL_SetVideoMode(1024,768, 0, SDL_OPENGL);
	
	SDL_WM_SetCaption( "Labyrinth Fighter /o/ \\o\\ \\o/ ", NULL );
	TTF_Init();
	TTF_Font *fntDeja = TTF_OpenFont( "DejaVuSerif.ttf", 12 );
	if (fntDeja == NULL) {
		exit(1);
	}
	TTF_CloseFont( fntDeja );
	glClearColor( 1,0,0,0);
	
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	//glOrtho( 0,0,1024, 768, 10, -10);
	gluPerspective( 75.0, 1024.0/768.0, 0.1, 1000.0 );
	
	/* Enable smooth shading */
    glShadeModel( GL_SMOOTH );

	glEnable(GL_DEPTH_TEST);

    /* Set the background black */
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
    
    /* Really Nice Perspective Calculations */
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
	
	maze.init(257);

	return 0;
}
