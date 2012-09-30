#pragma once
#include "math.h"
#include "frame_buffer.h"

struct Vertex {
    float x();
    float y();
    float z();
    float w();

    float r();
    float g();
    float b();
    float a();

    Vertex();
    Vertex(Point, Vector);
    Point point;
    Vector color;
    Vector normal;
    Vector u,v;
    void render(FrameBuffer&);
};
