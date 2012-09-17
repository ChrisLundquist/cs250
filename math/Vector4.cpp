#include "Vector4.h"

Vector4::Vector4(void) {
}

// Copy constructor, copies every component from the other Vector4
Vector4::Vector4(const Vector4& rhs) {
}

// Non-Default constructor, self explanatory
Vector4::Vector4(f32 xx, f32 yy, f32 zz, f32 ww) {
}

// Assignment operator, does not need to handle self assignment
Vector4& Vector4::operator=(const Vector4& rhs) {
}

// Unary negation Vector4::operator, negates all components and returns a copy
Vector4 Vector4::operator-(void) const {
}

// Basic Vector math operations. Add Vector to Vector B, or Subtract Vector A
// from Vector B, or multiply a vector with a scalar, or divide a vector by
// that scalar
Vector4 Vector4::operator+(const Vector4& rhs) const {
}
Vector4 Vector4::operator-(const Vector4& rhs) const {
}
Vector4 Vector4::operator*(const f32 rhs) const {
}
Vector4 Vector4::operator/(const f32 rhs) const {
}

// Same as above, just stores the result in the original vector
Vector4& Vector4::operator+=(const Vector4& rhs) {
}
Vector4& Vector4::operator-=(const Vector4& rhs) {
}
Vector4& Vector4::operator*=(const f32 rhs) {
}
Vector4& Vector4::operator/=(const f32 rhs) {
}

// Comparison Vector4::operators which should use an epsilon defined in
// Utilities.h to see if the value is within a certain range
// in which case we say they are equivalent.
bool Vector4::operator==(const Vector4& rhs) const {
}
bool Vector4::operator!=(const Vector4& rhs) const {
}

// Computes the dot product with the other vector. Treat it as 3D vector.
f32 Vector4::Dot(const Vector4& rhs) const {
}

// Computes the cross product with the other vector. Treat it as a 3D vector.
Vector4 Vector4::Cross(const Vector4& rhs) const {
}

// Computes the true length of the vector
f32 Vector4::Length(void) const {
}

// Computes the squared length of the vector
f32 Vector4::LengthSq(void) const {
}

// Normalizes the vector to make the final vector be of length 1. If the length is zero
// then this function should not modify anything.
void Vector4::Normalize(void) {
}

// Sets x,y,z to zeroes, w to defined value
void Vector4::Zero(void) {
}
void Vector4::Print(void) const
{
    printf("%5.3f, %5.3f, %5.3f, %5.3f\n",x,y,z,w);
}
