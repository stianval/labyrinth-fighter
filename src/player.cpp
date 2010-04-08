#include "port.h"
#include "player.h"

void Player::setCamera()
{
    glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective( 75.0, 1024.0/768.0, 0.1, 1000.0 );
	printf("%f\n%f\n%f\n\n", rot.getIndex(0,1), rot.getIndex(1,1), rot.getIndex(2,1));
	
	//rot.roll(0.0001);
	//rot.yaw(-0.001);
	//rot.pitch(0.002);
    gluLookAt(x,y,z,
			x+rot.getIndex(0,0), y+rot.getIndex(1,0), z+rot.getIndex(2,0),
			x+rot.getIndex(0,1), y+rot.getIndex(1,1), z+rot.getIndex(2,1));
}

void Player::process()
{
	SDL_Event key;
	if(SDL_PollEvent(&key)) {
		switch(key.type) {
			case SDL_PRESSED:
				switch(key.key.keysym.sym) {
					case SDLK_UP:
						printf("Hello!");
						rot.pitch(-0.001);
						break;
						
					case SDLK_s:
						rot.pitch(0.001);
						break;
				}
		}
	}
	
    x+=vx;
    y+=vy;
    z+=vz;
}
