#pragma once
#include "math.h"
#include "frame_buffer.h"

struct Vertex {
    Vertex();
    Vertex(Point, Vector);
    Point point;
    Vector color;
    Vector normal;
    Vector u,v;
    void render(FrameBuffer&);
};
