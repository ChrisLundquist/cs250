#pragma once

#include "graphics.h"

#define WIDTH 640
#define HEIGHT 480

#define PI 3.14159265358979323846
#define DEG_TO_RAD (PI / 180.0)

class FrameBuffer
{
    public:
        FrameBuffer(const unsigned &width, const unsigned &height);
        ~FrameBuffer();

        void Clear(const unsigned char &r, const unsigned char &g, const unsigned char &b);

        void Init(const unsigned int &w, const unsigned int &h);
        void SetPixel(const int &x, const int &y, const unsigned char &r, const unsigned char &g, const unsigned char &b);
        void GetPixel(const int &x, const int &y, unsigned char &r, unsigned char &g, unsigned char &b);

        unsigned char *buffer;
        int width;
        int height;
};
