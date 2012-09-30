#include "vertex.h"

Vertex::Vertex(){
    color = Vector();
    point = Point();
}

Vertex::Vertex(Point point, Vector color) {
    this->point = point;
    this->color = color;
}

void Vertex::render(FrameBuffer &buffer) {
    buffer.SetPixel(point.x, point.y, color.r, color.g, color.b);
}

float Vertex::x(){
    return point.x;
}

float Vertex::y(){
    return point.y;
}

float Vertex::z(){
    return point.z;
}

float Vertex::w(){
    return point.w;
}


float Vertex::r(){
    return color.r;
}

float Vertex::g(){
    return color.g;
}

float Vertex::b(){
    return color.b;
}

float Vertex::a(){
    return color.a;
}

