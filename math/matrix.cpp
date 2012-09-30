#include "matrix.h"

Matrix4::Matrix4(void) {
    Zero();
}

// Copy constructor, copies every entry from the other matrix.
Matrix4::Matrix4(const Matrix4& rhs) {
    for( unsigned i = 0; i < 4 * 4; i++)
        v[i] = rhs.v[i];
}

// Non-default constructor, self-explanatory
Matrix4::Matrix4(f32 mm00, f32 mm01, f32 mm02, f32 mm03,
        f32 mm10, f32 mm11, f32 mm12, f32 mm13,
        f32 mm20, f32 mm21, f32 mm22, f32 mm23,
        f32 mm30, f32 mm31, f32 mm32, f32 mm33) {
    m[0][0] = mm00;
    m[0][1] = mm01;
    m[0][2] = mm02;
    m[0][3] = mm03;

    m[1][0] = mm10;
    m[1][1] = mm11;
    m[1][2] = mm12;
    m[1][3] = mm13;

    m[2][0] = mm20;
    m[2][1] = mm21;
    m[2][2] = mm22;
    m[2][3] = mm23;

    m[3][0] = mm30;
    m[3][1] = mm31;
    m[3][2] = mm32;
    m[3][3] = mm33;
}

// Assignment operator, does not need to handle self-assignment
Matrix4& Matrix4::operator=(const Matrix4& rhs) {
    for( unsigned i = 0; i < 4 * 4; i++)
        v[i] = rhs.v[i];
    return *this;
}

// Multiplying a Matrix4 with a Vector4 or a Point4
Vector4 Matrix4::operator*(const Vector4& rhs) const {
    Vector4 tmp = Vector4(0,0,0,0);
    for( unsigned i = 0; i < 4; i++)
        for( unsigned j = 0; j < 4; j++)
            tmp.v[i] += rhs.v[j] * m[i][j];
    return tmp;

}

Point4  Matrix4::operator*(const Point4& rhs) const {
    Point4 tmp = Point4(0,0,0,0);
    for( unsigned i = 0; i < 4; i++)
        for( unsigned j = 0; j < 4; j++)
            tmp.v[i] += rhs.v[j] * m[i][j];
    return tmp;
}

// Basic Matrix arithmetic operations
Matrix4 Matrix4::operator+(const Matrix4& rhs) const {
    Matrix4 tmp = Matrix4();

    for(unsigned i = 0; i < 4 * 4; i++)
        tmp.v[i] = v[i] + rhs.v[i];

    return tmp;
}

Matrix4 Matrix4::operator-(const Matrix4& rhs) const {
    Matrix4 tmp = Matrix4();

    for(unsigned i = 0; i < 4 * 4; i++)
        tmp.v[i] = v[i] - rhs.v[i];

    return tmp;
}

Matrix4 Matrix4::operator*(const Matrix4& rhs) const {
    Matrix4 tmp = Matrix4();

    for (unsigned i = 0; i < 4; i++)
        for (unsigned j = 0; j < 4; j++)
            for (unsigned k = 0; k < 4; k++)
                tmp.m[i][j] += m[i][k] * rhs.m[k][j];
    return tmp;
}

// Similar to the three above except they modify
// the original
Matrix4& Matrix4::operator+=(const Matrix4& rhs) {
    for(unsigned i = 0; i < 4 * 4; i++)
        v[i] += rhs.v[i];

    return *this;
}

Matrix4& Matrix4::operator-=(const Matrix4& rhs) {
    for(unsigned i = 0; i < 4 * 4; i++)
        v[i] -= rhs.v[i];

    return *this;
}

Matrix4& Matrix4::operator*=(const Matrix4& rhs) {
    *this = *this * rhs;
    return *this;
}

// Scale/Divide the entire matrix by a float
Matrix4 Matrix4::operator*(const f32 rhs) const {
    Matrix4 tmp = Matrix4();
    for(unsigned i = 0; i < 4 * 4; i++)
        tmp.v[i] = v[i] * rhs;
    return tmp;
}

Matrix4 Matrix4::operator/(const f32 rhs) const {
    Matrix4 tmp = Matrix4();
    for(unsigned i = 0; i < 4 * 4; i++)
        tmp.v[i] = v[i] / rhs;
    return tmp;
}

// Same as previous
Matrix4& Matrix4::operator*=(const f32 rhs) {
    for(unsigned i = 0; i < 4 * 4; i++)
        v[i] *= rhs;
    return *this;
}

Matrix4& Matrix4::operator/=(const f32 rhs) {
    for(unsigned i = 0; i < 4 * 4; i++)
        v[i] /= rhs;
    return *this;
}

// Comparison Matrix4::operators which should use an epsilon defined in
// Utilities.h to see if the value is within a certain range
// in which case we say they are equivalent.
bool Matrix4::operator==(const Matrix4& rhs) const {
    for( unsigned i = 0; i < 4 * 4; i++)
        if( fabs(v[i] - rhs.v[i]) > EPSILON)
            return false;
    return true;
}

bool Matrix4::operator!=(const Matrix4& rhs) const {
    return !(*this == rhs);
}

// Zeroes out the entire matrix
void Matrix4::Zero(void) {
    for( unsigned i = 0; i < 4 * 4; i++)
        v[i] = 0;
}

// Builds the identity matrix
void Matrix4::Identity(void) {
    for( unsigned i = 0; i < 4; i++)
        for( unsigned j = 0; j < 4; j++)
            m[i][j] = !(i^j);
}


void Matrix4::Print(void) const {
    printf("--------------------------\n");
    printf("%5.3f %5.3f %5.3f %5.3f\n", m00, m01, m02, m03 );
    printf("%5.3f %5.3f %5.3f %5.3f\n", m10, m11, m12, m13 );
    printf("%5.3f %5.3f %5.3f %5.3f\n", m20, m21, m22, m23 );
    printf("%5.3f %5.3f %5.3f %5.3f\n", m30, m31, m32, m33 );
    printf("--------------------------\n");
}
