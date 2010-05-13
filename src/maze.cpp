#include <stdlib.h>
#include "maze.h"
#include "player.h"
#define DRAW_SIZE 8
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
				cube[ix][iy][iz].x = rand() & 2;
			} // for(z)
		} // for(y)
		printf("Creating layer %d/%d (%.2f%%)\n", ix+1, depth, float(ix+1)/float(depth)*100.0);
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
	
	// Find the parameters for the plane
	double Ap,Bp,Cp,Dp;
	Ap = player.rot.getIndex(0,0);
	Bp = player.rot.getIndex(1,0);
	Cp = player.rot.getIndex(2,0);
	Dp =-Ap*(player.x-Ap*w_size) - Bp*(player.y-Bp*w_size) - Cp*(player.z-Cp*w_size);
	
	for(int z=min_z;z<=max_z;z++){
		for(int y=min_y;y<=max_y;y++){
			for(int x=min_x;x<=max_x;x++){
				if (cube[x][y][z].x){
					// Purge invisible
					if((x*w_size)*Ap + (y*w_size)*Bp + (z*w_size)*Cp + Dp < 0) {
						continue;
					}
					
					Draw.resetCursor();
					Draw.scale(w_size,w_size,w_size);
					Draw.movePosition(x,y,z);
					Draw.render(box);
				}
			}
		}
	}
}
