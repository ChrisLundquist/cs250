#include "line.h"

struct Triangle {
    Vertex a,b,c;
    Triangle(Vertex, Vertex, Vertex);
    void render(FrameBuffer&);
};
