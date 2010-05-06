#include <stdlib.h>
#include "maze.h"
#include "player.h"

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

#define DRAW_SIZE 16
void Maze::draw()
{
	int cx,cy,cz;
	
	cx = getIndex(player.x);
	cy = getIndex(player.y);
	cz = getIndex(player.z);
	
	int min_x,max_x;
	int min_y,max_y;
	int min_z,max_z;
	min_x = (cx-DRAW_SIZE)<0		? 0			: cx-DRAW_SIZE;
	max_x = (cx+DRAW_SIZE)>=depth	? depth-1	: cx+DRAW_SIZE;
	
	min_y = (cy-DRAW_SIZE)<0		? 0			: cy-DRAW_SIZE;
	max_y = (cy+DRAW_SIZE)>=depth	? depth-1	: cy+DRAW_SIZE;
	
	min_z = (cz-DRAW_SIZE)<0		? 0			: cz-DRAW_SIZE;
	max_z = (cz+DRAW_SIZE)>=depth	? depth-1	: cz+DRAW_SIZE;
	
	for(int z=min_z;z<=max_z;z++){
		for(int y=min_y;y<=max_y;y++){
			for(int x=min_x;x<=max_x;x++){
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
