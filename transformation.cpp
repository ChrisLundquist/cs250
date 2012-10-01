#include <math.h>
#include "transformation.h"

#define PI 3.1415926535897932384626433832795028841971693993751058209749445923f

Transformation::Transformation() {
    stack = std::vector<Matrix>();
    current = Matrix();
}

Transformation& Transformation::push(Matrix transformation) {
    stack.push_back(transformation);
    current *= transformation;

    return *this;
}

Transformation& Transformation::pop() {
    stack.pop_back();

    current.Identity();

    for( unsigned i = 0; i < stack.size(); i++) {
        current *= stack[i];
    }

    return *this;
}

Matrix Transformation::transform() {
    return current;
}

Matrix Transformation::scale(float x, float y, float z) {
    Matrix scale = Matrix();

    scale.m[0][0] = x;
    scale.m[1][1] = y;
    scale.m[2][2] = z;
    scale.m[3][3] = 1;

    return scale;
}

Matrix Transformation::rotate(float x, float y, float z) {
    return rotate_z(z) * rotate_y(y) * rotate_x(x);
}

Matrix Transformation::translate(float x, float y, float z) {
    Matrix translate = Matrix();

    translate.m[3][0] = x;
    translate.m[3][1] = y;
    translate.m[3][2] = z;
    translate.m[3][3] = 1;

    return translate;
}

Matrix Transformation::rotate_x(float alpha) {
    alpha = PI * alpha / 180.0f;
    Matrix rotate = Matrix();
    rotate.Identity();

    rotate.m[1][1] = cosf(alpha);
    rotate.m[2][1] = -sinf(alpha);
    rotate.m[1][2] = sinf(alpha);
    rotate.m[2][2] = cosf(alpha);

    return rotate;
}

Matrix Transformation::rotate_y(float beta) {
    beta = PI * beta / 180.0f;
    Matrix rotate = Matrix();
    rotate.Identity();

    rotate.m[0][0] = cosf(beta);
    rotate.m[2][0] = sinf(beta);
    rotate.m[0][2] = -sinf(beta);
    rotate.m[2][2] = cosf(beta);
    return rotate;
}

Matrix Transformation::rotate_z(float gamma) {
    gamma = PI * gamma/ 180.0f;
    Matrix rotate = Matrix();
    rotate.Identity();

    rotate.m[0][0] = cosf(gamma);
    rotate.m[1][0] = -sinf(gamma);
    rotate.m[0][1] = sinf(gamma);
    rotate.m[1][1] = cosf(gamma);

    return rotate;
}

