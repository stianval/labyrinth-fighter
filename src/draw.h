#ifndef DRAW_H
#define DRAW_H
#include "port.h"

struct VertBuffer {
	const GLfloat *vlist;	// List of vertexes
	const GLushort *ilist;	// List of indices
	int numi;
};

class cDraw {
    public:
        VertBuffer makeBoxMesh();
		void resetCursor();
		void movePosition(double x,double y,double z);
		void rotate(double angle, double x, double y, double z);
		void scale(double x,double y,double z);
        void render(VertBuffer vbo);
};
extern class cDraw Draw;

#endif
