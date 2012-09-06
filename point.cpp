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

Point Point::operator-(Point& rhs) {
    return Point(x - rhs.x, y - rhs.y);
}
