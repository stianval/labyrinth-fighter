#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

#include "game.h"
#include "player.h"

int game(void)
{
	bool quit = false;
	SDL_Event event;
	Player pl;
	
	while(!quit) {
		if( SDL_PollEvent( &event ) ) {
			if( event.type == SDL_QUIT ) {
				quit=true;
			}
		}
		
		pl.process();
		pl.setCamera();
		
		glColor3f( 1.0, 1.0, 1.0);
		glBegin( GL_QUADS );
			glVertex3f( 0.0, 0.0, -10.0);
			glVertex3f( 0.0, 25.0,-10.0);
			glVertex3f(25.0, 25.0,-10.0);
			glVertex3f(15.0, 25.0,-10.0);
		glEnd();
		
		
		SDL_GL_SwapBuffers();
	}
	
	return 0;
}
