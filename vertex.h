#include "math.h"
#include "frame_buffer.h"

struct Vertex {
    Vertex();
    Vertex(Point, Vector);
    Point point;
    Vector color;
    void render(FrameBuffer&);
};
