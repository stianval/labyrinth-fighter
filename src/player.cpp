#include "port.h"
#include "player.h"

void Player::setCamera()
{
    glMatrixMode(GL_MODELVIEW);
    
    gluLookAt(x,y,z, x+10.0, y, z, x, y+10, z);
    
}

void Player::process()
{
    x+=vx;
    y+=vy;
    z+=vz;
}
