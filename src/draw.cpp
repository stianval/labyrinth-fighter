#include "draw.h"

// Global draw class
class cDraw Draw;

// Cube points
const int NUM_VERTEX = 3*8;
const int NUM_INDEX = 3*6*2;
const GLfloat v_cube[NUM_VERTEX] = {
	0,0,0,	1,0,0,
	1,1,0,	0,1,0,
	
	0,0,1,	1,0,1,
	1,1,1,	0,1,1
};

const GLushort i_cube[NUM_INDEX] = {
	0,1,2, 0,2,3, // Top
	4,5,6, 4,6,7, // Bottom
	
	0,3,4, 3,4,7, // Left side
	1,2,5, 2,5,6, // Right side
	
	0,1,4, 1,4,5, // Front
	3,2,7, 2,7,6, // Back
};

VertBuffer cDraw::makeBoxMesh()
{
    VertBuffer tmp;
    
    tmp.vlist = v_cube;
	tmp.ilist = i_cube;
	tmp.numi = NUM_INDEX;
    
    return tmp;
}

void cDraw::resetCursor()
{
	glMatrixMode( GL_MODELVIEW);
	glLoadIdentity();
}

void cDraw::movePosition(double x,double y,double z)
{	glTranslated(x,y,z);	}

void cDraw::rotate(double angle, double x,double y,double z)
{	glRotated(angle, x,y,z);	}

void cDraw::scale(double x,double y,double z)
{	glScaled(x,y,z);	}

void cDraw::render(VertBuffer vbo)
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	
	glVertexPointer( 3, GL_FLOAT, 0, vbo.vlist);
	glColorPointer( 3, GL_FLOAT, 0, vbo.vlist);
	
    glDrawElements( GL_TRIANGLES, vbo.numi, GL_UNSIGNED_SHORT, vbo.ilist);
	
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}
