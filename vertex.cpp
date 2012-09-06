#include "vertex.h"

Vertex::Vertex(){
    color = Color();
    point = Point();
}

Vertex::Vertex(Point point, Color color) {
    this->point = point;
    this->color = color;
}
