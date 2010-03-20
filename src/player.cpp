#include "port.h"
#include "player.h"
#include "debug.h"

#include <cstring>

Player::Player()
{
    x  = y  = z  = 0.0;
    vx = vy = vz = 0.0;

    PRINTV(sizeof(rot));

    memset(rot, 0, sizeof(rot));
    rot[0] = rot[4] = rot[8] = 1;
}

void Player::setCamera()
{
    glMatrixMode(GL_MODELVIEW);
    
    gluLookAt(x,y,z, x+10.0, y, z, x+10, y+10, z);
}

void Player::process()
{
    x += vx;
    y += vy;
    z += vz;
}
