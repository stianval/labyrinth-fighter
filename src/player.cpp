#include "port.h"
#include "player.h"
#include "debug.h"
#include <cstring>

Player::Player() {
	x=y=z=0.0;
	vx=vy=vz=0.0;
	droll=dpitch=dyaw=0.0;
	k_up=k_down=k_left=k_right=k_forth=k_break=k_tleft=k_tright=false;
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
	if(k_up)	dpitch-=0.002;
	if(k_down)	dpitch+=0.002;
	if(k_left)	droll-=0.002;
	if(k_right) droll+=0.002;
	if(k_tleft) dyaw-=0.002;
	if(k_tright) dyaw+=0.002;
	rot.yaw(dyaw);
	rot.roll(droll);
	rot.pitch(dpitch);
	dyaw *= 0.95;
	dpitch *= 0.95;
	droll *= 0.95;
	vx += double(k_forth)*rot.getIndex(0,0)*0.05;
	vy += double(k_forth)*rot.getIndex(1,0)*0.05;
	vz += double(k_forth)*rot.getIndex(2,0)*0.05;
	
	if(k_break)
		vx=vy=vz=0.0;
	
	x+=vx;
	y+=vy;
	z+=vz;
}
