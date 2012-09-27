#include <iostream>
#include "triangle.h"

Triangle::Triangle(Vertex a, Vertex b, Vertex c){
    this->a = a;
    this->b = b;
    this->c = c;
}

static Point cross_product(Point& a, Point& b) {
    Point p;
    p.x = a.y - b.y;
    p.y = b.x - a.x;
    //p.z = a.x * b.y - b.x * a.y;
    p.z = -0.5f * (p.x * (a.x + b.x) + p.y * (a.y + b.y));

    return p;
}

static float barything(Point& edge, Point& test) {
    return test.x * edge.x + test.y * edge.y + edge.z;
}

float Triangle::alpha(Point& test) {
    Point edge = cross_product(b.point, c.point);
    return barything(edge, test) / barything(edge, a.point);
}

float Triangle::beta(Point& test) {
    Point edge = cross_product(c.point, a.point);
    return barything(edge, test) / barything(edge, b.point);
}

float Triangle::gamma(Point& test) {
    Point edge = cross_product(a.point, b.point);
    return barything(edge, test) / barything(edge, c.point);
}

bool Triangle::includes(Point& point) {
    // Tie Breaker so alpha doesn't get an >=
    return alpha(point) > 0 and beta(point) >= 0 and gamma(point) >= 0;
}

void Triangle::barycentric(FrameBuffer& buffer){
    // TODO use a bounding quad
    for(int y = 0; y < buffer.height; y++)
        for(int x = 0; x < buffer.width; x++) {
            Point point = Point(x, y);
            Vertex pixel = calculate_pixel(point);
            if(includes(pixel.point))
                pixel.render(buffer);
        }
}

Vertex Triangle::calculate_pixel( Point& point) {
    float alpha = this->alpha(point);
    float beta  = this->beta(point);
    float gamma = this->gamma(point);

    Vector color = a.color * alpha + b.color * beta + c.color * gamma;

    return Vertex( point, color);
}

void Triangle::render(FrameBuffer& buffer) {
    barycentric(buffer);
}

//FIXME
void Triangle::scanline(FrameBuffer& buffer) {
    Vertex top, bottom, middle, left, right;

    top    = this->top();
    middle = this->middle();
    bottom = this->bottom();
    left   = top;
    right  = top;

    //std::cout << "Top:" << top.point << "Middle:" << middle.point << "Bottom:" << bottom.point << std::endl;

    Line(top, middle).render(buffer);
    Line(top, bottom).render(buffer);
    Line(middle, bottom).render(buffer);

    if(top.point.y - bottom.point.y == 0)
        return; //TODO flat triangles?

    // Top half
    //while( left.point.y > middle.point.y){
    //    std::cout << "Left: " << left.point << " Right: " << right.point << std::endl;
    //}
}


Vertex& Triangle::top() {
    if(a.point.y > b.point.y and a.point.y > c.point.y)
        return a;
    else if(b.point.y > a.point.y and b.point.y > c.point.y)
        return b;
    else if(c.point.y >= a.point.y and c.point.y >= b.point.y)
        return c;
    else
        return a;
}

Vertex& Triangle::bottom() {
    if(a.point.y < b.point.y and a.point.y < c.point.y)
        return a;
    else if(b.point.y < a.point.y and b.point.y < c.point.y)
        return b;
    else if(c.point.y <= a.point.y and c.point.y <= b.point.y)
        return c;
    else
        return a;
}

Vertex& Triangle::middle() {
    if(a.point.y < b.point.y and a.point.y > c.point.y)
        return a;
    else if(b.point.y < a.point.y and b.point.y > c.point.y)
        return b;
    else if(c.point.y <= a.point.y and c.point.y >= b.point.y)
        return c;
    else
        return a;
}


