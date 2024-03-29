#include "port.h"
#include "init.h"
#include "maze.h"
#include "utilities.h"
#include "debug.h"

int init(void)
{
	// Initialize SDL stuff
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_SetVideoMode(1024,768, 0, SDL_OPENGL);
	SDL_WM_SetCaption( "Labyrinth Fighter /o/ \\o\\ \\o/ ", NULL );
	
	// Prepare font
	//TTF_Init();
	//fontToDraw = TTF_OpenFont( "DejaVuSerif.ttf", 12 );
	glClearColor( 1,0,0,0);
	
	// Initialize OpenGL
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	//glOrtho( 0,0,1024, 768, 10, -10);
	gluPerspective( 75.0, 1024.0/768.0, 0.1, 1000.0 );
	
	/* Enable smooth shading */
    glShadeModel( GL_SMOOTH );

	glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    /* Set the background black */
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
    
    /* Really Nice Perspective Calculations */
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
	
	// Build the maze
	maze.init(MAZE_SIZE);

    // Initialize os specific stuff. Must be called after some other stuff here in init, so do not move.
    os_init();

	return 0;
}

void cleanup(){
	//TTF_CloseFont(fontToDraw);
    //TTF_Quit();
    SDL_Quit();
}
