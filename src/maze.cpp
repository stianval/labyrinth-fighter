#include <stdlib.h>
#include "maze.h"

class Maze maze;

void Maze::init(int depth, double w_size)
{
	this->depth = depth;
	this->w_size = w_size;
	
	box = Draw.makeBoxMesh();
	
	cube = new Cube**[depth];
	for(int ix = 0; ix<depth; ix++) {
		cube[ix] = new Cube*[depth];
		
		for(int iy=0; iy<depth; iy++) {
			cube[ix][iy] = new Cube[depth];
			
			for(int iz=0; iz<depth; iz++) {
				cube[ix][iy][iz].x = rand() & 1;
			} // for(z)
		} // for(y)
	} // for(x)
}

bool Maze::checkPointInBox(double x, double y, double z)
{	int ix = getIndex(x);
	int iy = getIndex(y);
	int iz = getIndex(z);
	if(ix<0 || ix>=depth) return false;
	if(iy<0 || iy>=depth) return false;
	if(iz<0 || iz>=depth) return false;
	
	return isWall(ix,iy,iz);
}

void Maze::draw()
{
	for(int z=0;z<depth;z++){
		for(int y=0;y<depth;y++){
			for(int x=0;x<depth;x++) {
				if (cube[x][y][z].x){
					Draw.resetCursor();
					Draw.scale(100,100,100);
					Draw.movePosition(x,y,z);
					Draw.render(box);
				}
			}
		}
	}
}
