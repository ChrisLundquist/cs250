#include "Vector4.h"

Vector4::Vector4(void) {
    Zero();
}

// Copy constructor, copies every component from the other Vector4
Vector4::Vector4(const Vector4& rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    w = rhs.w;
}

// Non-Default constructor, self explanatory
Vector4::Vector4(f32 xx, f32 yy, f32 zz, f32 ww) {
    x = xx;
    y = yy;
    z = zz;
    w = ww;
}

// Assignment operator, does not need to handle self assignment
Vector4& Vector4::operator=(const Vector4& rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    w = rhs.w;
    return *this;
}

// Unary negation Vector4::operator, negates all components and returns a copy
Vector4 Vector4::operator-(void) const {
    return Vector4(-x, -y, -z,-w);
}

// Basic Vector math operations. Add Vector to Vector B, or Subtract Vector A
// from Vector B, or multiply a vector with a scalar, or divide a vector by
// that scalar
Vector4 Vector4::operator+(const Vector4& rhs) const {
    return Vector4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
}

Vector4 Vector4::operator-(const Vector4& rhs) const {
    return Vector4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
}

Vector4 Vector4::operator*(const f32 rhs) const {
    return Vector4(x * rhs, y * rhs, z * rhs, w * rhs);
}

Vector4 Vector4::operator/(const f32 rhs) const {
    return Vector4(x / rhs, y / rhs, z / rhs, w / rhs);
}

// Same as above, just stores the result in the original vector
Vector4& Vector4::operator+=(const Vector4& rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    w += rhs.w;
    return *this;
}

Vector4& Vector4::operator-=(const Vector4& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    w -= rhs.w;
    return *this;
}

Vector4& Vector4::operator*=(const f32 rhs) {
    x *= rhs;
    y *= rhs;
    z *= rhs;
    w *= rhs;
    return *this;
}

Vector4& Vector4::operator/=(const f32 rhs) {
    x /= rhs;
    y /= rhs;
    z /= rhs;
    w /= rhs;
    return *this;
}

// Comparison Vector4::operators which should use an epsilon defined in
// Utilities.h to see if the value is within a certain range
// in which case we say they are equivalent.
bool Vector4::operator==(const Vector4& rhs) const {
    for( unsigned i = 0; i < 4; i++)
        if( fabs(v[i] - rhs.v[i]) > EPSILON)
            return false;
    return true;
}

bool Vector4::operator!=(const Vector4& rhs) const {
    return (*this == rhs);
}

// Computes the dot product with the other vector. Treat it as 3D vector.
f32 Vector4::Dot(const Vector4& rhs) const {
    return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
}

// Computes the cross product with the other vector. Treat it as a 3D vector.
Vector4 Vector4::Cross(const Vector4& rhs) const {
    float x = y * rhs.z - z * rhs.y;
    float y = -(x * rhs.z - z * rhs.x);
    float z = x * rhs.y - rhs.x * y;
    return Vector4(x, y, z, 0);
}

// Computes the true length of the vector
f32 Vector4::Length(void) const {
    return sqrt(LengthSq());
}

// Computes the squared length of the vector
f32 Vector4::LengthSq(void) const {
    return x * x + y * y + z * z + w * w;
}

// Normalizes the vector to make the final vector be of length 1. If the length is zero
// then this function should not modify anything.
void Vector4::Normalize(void) {
    float length = Length();

    if(length == 0.0f)
        return;

    *this /= Length();
}

// Sets x,y,z to zeroes, w to defined value
void Vector4::Zero(void) {
    x = 0;
    y = 0;
    z = 0;
    w = 0;
}
void Vector4::Print(void) const
{
    printf("%5.3f, %5.3f, %5.3f, %5.3f\n",x,y,z,w);
}
