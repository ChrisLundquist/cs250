#include "vertex.h"

struct Line {
    Line(Vertex, Vertex);
    Vertex a, b;
    void render(FrameBuffer&);
};
