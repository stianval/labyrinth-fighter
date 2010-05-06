#ifndef MAZE_H
#define MAZE_H
#include "draw.h"

class Maze {
	struct Cube {
		int x;
	};
	
	public:
		void init(int depth);
		void draw();
		
	private:
		Cube ***cube;
		int depth;
		
		VertBuffer box;
};

extern class Maze maze;

#endif
