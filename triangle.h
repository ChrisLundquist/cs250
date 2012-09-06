#include "line.h"

struct Triangle {
    Vertex a,b,c;
    Triangle(Vertex, Vertex, Vertex);
    void render(FrameBuffer&);
    bool includes(Point&);
private:
    void barycentric(FrameBuffer&);
    //Vertex& top();
    //Vertex& bottom();
    //Vertex& middle();
};
