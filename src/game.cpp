#include <math.h>
#include "port.h"
#include "game.h"
#include "player.h"
#include "draw.h"
#include "maze.h"

int game(void)
{
	double k = 0.0, l=0.0, m=0.0;
	int prev,cur;
	bool quit = false;
	SDL_Event event;
	
	prev = SDL_GetTicks();
	while(!quit) {
		while( SDL_PollEvent( &event ) ) {
			switch( event.type ) {
				case SDL_QUIT:
					quit=true;
					break;
					
				case SDL_KEYDOWN:
				case SDL_KEYUP:
					{
						bool state = event.key.state;
						player.procState(event.key.keysym.sym, state);
						switch( event.key.keysym.sym ) {
                            /*
							case SDLK_UP: pl.k_up = state;	break;
							case SDLK_DOWN: pl.k_down = state;	break;
							case SDLK_LEFT: pl.k_left = state;	break;
							case SDLK_RIGHT: pl.k_right = state;break;
							case SDLK_w: pl.k_forth = state; break;
                            case SDLK_b: pl.k_brakedebug = state; break;
                            case SDLK_s: pl.k_brake = state; break;
							case SDLK_a: pl.k_tleft = state; break;
							case SDLK_d: pl.k_tright = state; break;
                            */
							/*
                            case SDLK_UP:    set_state(&pl.keystate, K_UP, state); break;
							case SDLK_DOWN:  set_state(&pl.keystate, K_DOWN, state); break;
							case SDLK_LEFT:  set_state(&pl.keystate, K_LEFT, state); break;
							case SDLK_RIGHT: set_state(&pl.keystate, K_RIGHT, state); break;
							case SDLK_w:     set_state(&pl.keystate, K_FORTH, state); break;
                            case SDLK_b:     set_state(&pl.keystate, K_BRAKEDEBUG, state); break;
                            case SDLK_s:     set_state(&pl.keystate, K_BRAKE, state); break;
							case SDLK_a:     set_state(&pl.keystate, K_TLEFT, state); break;
							case SDLK_d:     set_state(&pl.keystate, K_TRIGHT, state); break;|
							*/
                            case SDLK_ESCAPE:   quit=true; break;
						}
					}
					break;
			}
		}
		
		if(SDL_GetTicks() > prev+(1000/60)) {
			prev = SDL_GetTicks();
			
			player.process();
			player.setCamera();
			
            /*
			Draw.resetCursor();
			Draw.movePosition(0,0, -6);
			Draw.rotate(k, 0.0,1.0,0.0);
			Draw.rotate(l, 1.0,0.0,0.0);
			Draw.rotate(m, 0.0,0.0,1.0);
			// Try to center the cube for rotation
			Draw.movePosition(-0.5,-0.5,-0.5);
			//k+=0.1; l+=0.01; m+=0.001;
			//Draw.render(mybox);
			
			Draw.movePosition(-2,+1,-4);		Draw.render(mybox);
			Draw.movePosition(+4,-2,+8);		Draw.render(mybox);
			
			Draw.movePosition(-2,+1,-4);
			Draw.scale(0.5,0.5,0.5);
			Draw.movePosition(3,3,0);		Draw.render(mybox);
			Draw.movePosition(-6,-6,0);		Draw.render(mybox);
		
			Draw.resetCursor();
			Draw.scale(10000,10000,10000);


            /*

			Draw.resetCursor();
			//glDisable( GL_DEPTH_TEST);
			Draw.movePosition(-500,-500,-500);
			Draw.scale(1000,1000,1000);		Draw.render(mybox);
			
            */
			
			maze.draw();

			/* Draw it to the screen */
			SDL_GL_SwapBuffers( );
			glClearColor( k/1000.0,l/1000.0,m/1000.0, 0.0f );
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
	}
	
	return 0;
}
