#include "port.h"
#include "player.h"
#include "debug.h"
#include <cstring>

#define ROT_ADJ 0.002
#define VEL_ADJ 0.005

Player::Player() {
	x=y=z=0.0;
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

	x+=vx;
	y+=vy;
	z+=vz;
}
