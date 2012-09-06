#include "line.h"
#include <stdlib.h> // abs

Line::Line(Vertex a, Vertex b) {
    this->a = a;
    this->b = b;
}

void Line::render(FrameBuffer& buffer) {
    Vertex tmp = a;
    int dx = abs(b.point.x - a.point.x);
    int dy = abs(b.point.y - a.point.y);

    int sx = a.point.x < b.point.x ? 1 : -1;
    int sy = a.point.y < b.point.y ? 1 : -1;
    int err = dx - dy;
    int done = 0;

    while(!done) {
        tmp.render(buffer);
        done = tmp.point.x == b.point.x and tmp.point.y == b.point.y;

        int e2 = 2*err;

        if(e2 > -dy) {
            err -= dy;
            tmp.point.x += sx;
        }

        if( e2 <  dx) {
            err += dx;
            tmp.point.y += sy;
        }
    }
}
