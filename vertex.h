#include "color.h"
#include "point.h"
#include "frame_buffer.h"

struct Vertex {
    Vertex();
    Vertex(Point, Color);
    Color color;
    Point point;
    void render(FrameBuffer&);
};
