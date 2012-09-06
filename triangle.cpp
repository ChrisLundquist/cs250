#include "triangle.h"

Triangle::Triangle(Vertex a, Vertex b, Vertex c){
    this->a = a;
    this->b = b;
    this->c = c;
}

// FIXME
static Point edgify(Point a, Point b) {
    Point p;
    p.x = a.y - b.y;
    p.y = b.x - a.x;
    p.z = a.x * b.y + b.x * a.y;

    return p;
}

// FIXME
static float barything(Point edge, Point test) {
    return test.x * edge.x + test.y * edge.y + edge.z;
}

// FIXME
bool Triangle::includes(Point& point) {
    Point e1 = edgify(b.point,c.point);
    Point e2 = edgify(c.point,a.point);
    Point e3 = edgify(a.point,b.point);

    float alpha = barything(e1, point) / barything(e1, a.point);
    float beta = barything(e2, point) / barything(e2, b.point);
    float gamma = barything(e2, point) / barything(e2, c.point);

    return \
        0 <= alpha && alpha <= 1 and
        0 <= beta && beta <= 1 and
        0 <= gamma && gamma <= 1;
}

// FIXME
void Triangle::barycentric(FrameBuffer& buffer){
    // TODO use a bounding quad
    for(int y = 0; y < buffer.height; y++)
        for(int x = 0; x < buffer.width; x++) {
            Vertex point = Vertex(Point(x,y),a.color);
            if(includes(point.point))
                point.render(buffer);
        }
}

void Triangle::render(FrameBuffer& buffer) {
    barycentric(buffer);
}


//static void scanline(FrameBuffer& buffer) {
//    Vertex top, bottom, middle;
//
//    top    = this->top();
//    middle = this->middle();
//    bottom = this->bottom();
//
//    Line(top,middle).render(buffer);
//    Line(top,bottom).render(buffer);
//    Line(middle,bottom).render(buffer);
//
//    if(top.point.y - bottom.point.y == 0)
//      return; //TODO flat triangles?
//}


//Vertex& Triangle::top() {
//  if(a.point.y > b.point.y and a.point.y > c.point.y)
//    return a;
//  else if(b.point.y > a.point.y and b.point.y > c.point.y)
//    return b;
//  else if(c.point.y >= a.point.y and c.point.y >= b.point.y)
//    return c;
//  else
//    return a;
//}
//
//Vertex& Triangle::bottom() {
//  if(a.point.y < b.point.y and a.point.y < c.point.y)
//    return a;
//  else if(b.point.y < a.point.y and b.point.y < c.point.y)
//    return b;
//  else if(c.point.y <= a.point.y and c.point.y <= b.point.y)
//    return c;
//  else
//    return a;
//}
//
//Vertex& Triangle::middle() {
//  if(a.point.y < b.point.y and a.point.y > c.point.y)
//    return a;
//  else if(b.point.y < a.point.y and b.point.y > c.point.y)
//    return b;
//  else if(c.point.y <= a.point.y and c.point.y >= b.point.y)
//    return c;
//  else
//    return a;
//}


