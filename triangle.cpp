#include "triangle.h"

Triangle::Triangle(Vertex a, Vertex b, Vertex c){
    this->a = a;
    this->b = b;
    this->c = c;
}

void Triangle::render(FrameBuffer& buffer) {
    //TODO
    a.render(buffer);
    b.render(buffer);
    c.render(buffer);
}
