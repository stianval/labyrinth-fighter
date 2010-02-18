#ifndef DRAW_H
#define DRAW_H
#include "port.h"

struct VertBuffer {
    int numv;
    GLuint verts;
};

class cDraw {
    public:
        VertBuffer makeBoxMesh();
        void render(VertBuffer vbo, double x=0, double y=0, double z=0);
};
extern class cDraw Draw;

#endif
