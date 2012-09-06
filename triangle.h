#include "line.h"

struct Triangle {
    Vertex a,b,c;
    Triangle(Vertex, Vertex, Vertex);
    void render(FrameBuffer&);
    bool includes(Point&);
    Vertex& top();
    Vertex& bottom();
    Vertex& middle();
private:
    void barycentric(FrameBuffer&);
    void scanline(FrameBuffer&);
};
