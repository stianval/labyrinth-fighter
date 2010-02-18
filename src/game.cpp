#include "port.h"
#include "game.h"
#include "player.h"
#include "draw.h"

int game(void)
{
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
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		static GLfloat rquad;
		
	  	/* Move Right 3 Units */
		glLoadIdentity( );
		glTranslatef( 0.0f, 0.0f, -6.0f );
		
		//glRotatef(rquad,1.0f,1.0f,1.0f);

		glColor3f(1.0f, 0.0f, 0.0f );      
		Draw.render(mybox);
		
		//rquad-=0.15f;

		/* Draw it to the screen */
		SDL_GL_SwapBuffers( );
		
		
		}
	
	return 0;
}
