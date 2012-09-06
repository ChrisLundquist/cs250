#include <math.h>
#include "point.h"

Point::Point() {
    x = 0;
    y = 0;
    z = 0;
    t = 0;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
    z = 0;
    t = 0;
}

float Point::length() {
    return sqrt( x * x + y * y);
}

Point Point::normalize() {
    float length = this->length();
    return Point( x / length, y / length);
}

Point Point::operator-(Point& rhs) {
    return Point(x - rhs.x, y - rhs.y);
}

Point Point::operator+(Point& rhs) {
    return Point(x + rhs.x, y + rhs.y);
}

Point& Point::operator+=(Point& rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
}
