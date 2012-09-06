#include "vertex.h"

Vertex::Vertex(){
    color = Color();
    point = Point();
}

Vertex::Vertex(Point point, Color color) {
    this->point = point;
    this->color = color;
}

void Vertex::render(FrameBuffer &buffer) {
    buffer.SetPixel(point.x, point.y, color.r, color.g, color.b);
}
