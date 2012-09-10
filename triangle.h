#include "line.h"

struct Triangle {
    Vertex a,b,c;
    Triangle(Vertex, Vertex, Vertex);
    void render(FrameBuffer&);
    bool includes(Point&);
    Vertex& top();
    Vertex& bottom();
    Vertex& middle();
    float alpha(Point&);
    float beta(Point&);
    float gamma(Point&);
    Vertex calculate_pixel(Point&);
private:
    void barycentric(FrameBuffer&);
    void scanline(FrameBuffer&);
};
