#include "port.h"
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
	
	/* Enable smooth shading */
    glShadeModel( GL_SMOOTH );

	glEnable(GL_DEPTH_TEST);

    /* Set the background black */
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );   
    
    /* Really Nice Perspective Calculations */
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
	
	return 0;
}
