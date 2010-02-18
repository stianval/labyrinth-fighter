#include "draw.h"

// Global draw class
class cDraw Draw;

VertBuffer cDraw::makeBoxMesh()
{
    VertBuffer tmp;
    
    glGenBuffers(1, &tmp.verts);
    glBindBuffer( GL_ARRAY_BUFFER, tmp.verts );
    
    // Cube points
    const int NUM_POINTS = 3*6*6;
    const float cube[NUM_POINTS] = {
            0,0,0, 1,0,0, 0,1,0, // Front
            0,1,0, 1,1,0, 1,0,0,
            
            0,0,1, 1,0,1, 0,1,1, // Back
            1,0,1, 1,1,1, 0,1,1,
            
            0,0,0, 0,0,1, 0,1,1, // Left side
            0,0,0, 0,1,0, 0,1,1,
            
            1,0,0, 1,0,1, 1,1,1, // Right side
            1,0,0, 1,1,0, 1,1,1,
            
            0,0,0, 0,0,1, 0,1,0, // Top
            0,1,0, 0,1,1, 0,0,1,
            
            1,0,0, 1,0,1, 1,1,0, // Bottom
            1,1,0, 1,1,1, 1,0,1
        };
    
    glBufferData( tmp.verts, sizeof(float)*3*6*6, &cube, GL_STATIC_READ);
    tmp.numv = NUM_POINTS;
    
    return tmp;
}

void cDraw::render(VertBuffer vbo, double x,double y,double z)
{
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	glTranslatef( x,y,z );
	
    glBindBuffer( GL_ARRAY_BUFFER, vbo.verts );
    glVertexPointer(3, GL_FLOAT, 0, NULL );
    glDrawArrays( GL_TRIANGLES, 0, vbo.numv );
}
