#include "color.h"
#include "point.h"

struct Vertex {
    Vertex();
    Vertex(Point, Color);
    Color color;
    Point point;
};
