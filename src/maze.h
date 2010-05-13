#ifndef MAZE_H
#define MAZE_H
#include "draw.h"

#define MAZE_SIZE 257
 
class Maze {
	struct Cube {
		int x;
	};
	
	public:
		void init(int depth, double w_size=100.0);
		void draw();
		
		bool checkPointInBox(double x, double y, double z);
		bool isWall(int x,int y,int z) { return cube[x][y][z].x; }
		int getIndex(double x) { return int(x/w_size); }
	private:
		Cube ***cube;
		int depth;
		double w_size;
		
		VertBuffer box;
};

extern class Maze maze;

#endif
