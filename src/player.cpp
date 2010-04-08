#include "port.h"
#include "player.h"

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
	if(k_up)	rot.pitch(0.05);
	if(k_down)	rot.pitch(-0.05);
	if(k_left)	rot.roll(-0.05);
	if(k_right) rot.roll(0.05);
	vx += double(k_forth)*rot.getIndex(0,0)*0.05;
	vy += double(k_forth)*rot.getIndex(1,0)*0.05;
	vz += double(k_forth)*rot.getIndex(2,0)*0.05;
	
	if(k_break)
		vx=vy=vz=0.0;
	
	x+=vx;
	y+=vy;
	z+=vz;
}
