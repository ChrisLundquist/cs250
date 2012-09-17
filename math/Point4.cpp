#include "Point4.h"

Point4::Point4(void) {
    Zero();
}

// Copy constructor, copies every component from the other Point4
Point4::Point4(const Point4& rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    w = rhs.w;
}

// Non-Default constructor, self-explanatory
Point4::Point4(f32 xx, f32 yy, f32 zz, f32 ww) {
    x = xx;
    y = yy;
    z = zz;
    w = ww;
}

// Assignment operator, copies every component from the other Point4
Point4& Point4::operator=(const Point4& rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    w = rhs.w;
    return *this;
}

// Unary negation operator, negates every component and returns a copy
Point4 Point4::operator-(void) const {
    return Point4(-x, -y, -z,-w);
}

// Binary subtraction operator, Subtract two Point4s and you get a Vector4
Vector4 Point4::operator-(const Point4&  rhs) const {
    return Vector4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
}

// Basic vector math operations with points, you can add a Vector4 to a Point4, or subtract
// a Vector4 from a Point4
Point4  Point4::operator+ (const Vector4& rhs) const {
    return Point4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
}

Point4  Point4::operator- (const Vector4& rhs) const {
    return Point4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
}

// Same as previous two Point4::operators, just modifies the original instead of returning a copy
Point4& Point4::operator+=(const Vector4& rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    w += rhs.w;
    return *this;
}

Point4& Point4::operator-=(const Vector4& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    w -= rhs.w;
    return *this;
}

// Comparison Point4::operators which should use an epsilon defined in
// Utilities.h to see if the value is within a certain range
// in which case we say they are equivalent.
bool Point4::operator==(const Point4& rhs) const {
    return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w;
}

bool Point4::operator!=(const Point4& rhs) const {
    return !(*this == rhs);
}

// Sets x,y,z to zeroes, w to defined value
void Point4::Zero(void) {
    x = 0;
    y = 0;
    z = 0;
    w = 1;
}

void Point4::Print(void) const
{
    printf("%5.3f, %5.3f, %5.3f, %5.3f\n",x,y,z,w);
}
