#include "port.h"
#include "player.h"
#include "debug.h"
#include "maze.h"
#include <cstring>

#define ROT_ADJ 0.002
#define VEL_ADJ 0.050
#define BOUNCE 0.4
class Player player;

Player::Player() {
	//x=y=z=-10;
    x=y=z=64*100.0+50.0;
	vx=vy=vz=0.0;
	droll=dpitch=dyaw=0.0;
	keystate = 0;
    //k_up=k_down=k_left=k_right=k_forth=k_brake=k_tleft=k_tright=k_brakedebug=false;
	rot.roll(-0.5);
}

void Player::setCamera()
{
    glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective( 75.0, 1024.0/768.0, 0.1, 1.0e6 );
	
    gluLookAt(x,y,z,
			x+rot.getIndex(0,0), y+rot.getIndex(1,0), z+rot.getIndex(2,0),
			rot.getIndex(0,1), rot.getIndex(1,1), rot.getIndex(2,1));

	glEnable(GL_FOG);
	float col[] = {1,1,1};
	float pos[3];
		pos[0] = x;
		pos[1] = y;
		pos[2] = z;
	glFogi(GL_FOG_COORD_SRC, GL_FOG_COORD);
	glFogfv(GL_FOG_COLOR,col);
	glFogi(GL_FOG_MODE, GL_LINEAR);
	glFogf(GL_FOG_START, 100.0*10);
	glFogf(GL_FOG_END, 100.0*16);
}

void Player::process()
{
    /*
	if(k_up)	 dpitch-=0.002;
	if(k_down)	 dpitch+=0.002;
	if(k_left)	 droll-=0.002;
	if(k_right)  droll+=0.002;
	if(k_tleft)  dyaw-=0.002;
	if(k_tright) dyaw+=0.002;
    */
	if(keystate & K_UP)	     dpitch-=ROT_ADJ;
	if(keystate & K_DOWN)	 dpitch+=ROT_ADJ;
	if(keystate & K_LEFT)	 droll-=ROT_ADJ;
	if(keystate & K_RIGHT)   droll+=ROT_ADJ;
	if(keystate & K_TLEFT)   dyaw-=ROT_ADJ;
	if(keystate & K_TRIGHT)  dyaw+=ROT_ADJ;

	rot.yaw(dyaw);
	rot.roll(droll);
	rot.pitch(dpitch);
	dyaw *= 0.95;
	dpitch *= 0.95;
	droll *= 0.95;
    /*
	vx += double(k_forth)*rot.getIndex(0,0)*0.005;
	vy += double(k_forth)*rot.getIndex(1,0)*0.005;
	vz += double(k_forth)*rot.getIndex(2,0)*0.005;
	*/
    double forth = (double)!!(keystate & K_FORTH);
    vx += forth*rot.getIndex(0,0)*VEL_ADJ;
	vy += forth*rot.getIndex(1,0)*VEL_ADJ;
	vz += forth*rot.getIndex(2,0)*VEL_ADJ;
	
    /*
    if(k_brakedebug)
		vx=vy=vz=0.0;
	if(k_brake) {
		vx*=0.95;
		vy*=0.95;
		vz*=0.95;
	}
    */

    if(keystate & K_BRAKEDEBUG){
        vx = vy = vz = 0.0;
    }
    if(keystate & K_BRAKE){
		vx*=0.95;
		vy*=0.95;
		vz*=0.95;
    }
	ox = x;
	oy = y;
	oz = z;
	x+=vx;
	y+=vy;
	z+=vz;
	if (maze.checkPointInBox(x,y,z)) {
		if (maze.getIndex(oz)-maze.getIndex(z) != 0) {
			z = oz;
			vz *= -BOUNCE;
			vy *= BOUNCE;
			vz *= BOUNCE;
		}
		if (maze.getIndex(oy)-maze.getIndex(y) != 0) {
			y = oy;
			vy *= -BOUNCE;
			vx *= BOUNCE;
			vz *= BOUNCE;
		}
		if (maze.getIndex(ox)-maze.getIndex(x) != 0) {
			x = ox;
			vx *= -BOUNCE;
			vy *= BOUNCE;
			vz *= BOUNCE;
		}
	}
}
void Player::procState(int key, bool state) {
	switch( key) {
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

		case SDLK_UP:    set_state(&keystate, K_UP, state); break;
		case SDLK_DOWN:  set_state(&keystate, K_DOWN, state); break;
		case SDLK_LEFT:  set_state(&keystate, K_LEFT, state); break;
		case SDLK_RIGHT: set_state(&keystate, K_RIGHT, state); break;
		case SDLK_w:     set_state(&keystate, K_FORTH, state); break;
		case SDLK_b:     set_state(&keystate, K_BRAKEDEBUG, state); break;
		case SDLK_s:     set_state(&keystate, K_BRAKE, state); break;
		case SDLK_a:     set_state(&keystate, K_TLEFT, state); break;
		case SDLK_d:     set_state(&keystate, K_TRIGHT, state); break;

		
	}
}

