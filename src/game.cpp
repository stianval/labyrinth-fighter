#include <math.h>
#include "port.h"
#include "game.h"
#include "player.h"
#include "draw.h"

int game(void)
{
	double k = 0.0, l=0.0, m=0.0;
	bool quit = false;
	SDL_Event event;
	Player pl;
	
	VertBuffer mybox =  Draw.makeBoxMesh();
	
	while(!quit) {
	    
		if( SDL_PollEvent( &event ) ) {
			if( event.type == SDL_QUIT ) {
				quit=true;
			}
		}
		
		pl.process();
		pl.setCamera();
		
		Draw.resetCursor();
		Draw.movePosition(0,0, -6);
		Draw.rotate(k, 0.0,1.0,0.0);
		Draw.rotate(l, 1.0,0.0,0.0);
		Draw.rotate(m, 0.0,0.0,1.0);
		// Try to center the cube for rotation
		Draw.movePosition(-0.5,-0.5,-0.5);
		//k+=0.1; l+=0.01; m+=0.001;
		Draw.render(mybox);
		
		Draw.movePosition(-2,+1,-4);		Draw.render(mybox);
		Draw.movePosition(+4,-2,+8);		Draw.render(mybox);
		
		Draw.movePosition(-2,+1,-4);
		Draw.scale(0.5,0.5,0.5);
		Draw.movePosition(3,3,0);		Draw.render(mybox);
		Draw.movePosition(-6,-6,0);		Draw.render(mybox);
		
		/* Draw it to the screen */
		SDL_GL_SwapBuffers( );
		glClearColor( k/1000.0,l/1000.0,m/1000.0, 0.0f );
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
	
	return 0;
}
