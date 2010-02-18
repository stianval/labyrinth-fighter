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
        void render(VertBuffer vbo);
};
extern class cDraw Draw;

#endif
