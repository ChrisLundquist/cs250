#include "camera.h"

Camera::Camera() {
    top    = 0;
    bottom = 0;
    left   = 0;
    right  = 0;

    focal = 0;
    near  = 0;
    far   = 0;
}

Matrix Camera::get_projection() {
    Matrix projection = Matrix();

    projection.m[0][0] = 2.0f * near / (right - left);
    projection.m[0][2] = (right + left) / (right - left);

    projection.m[1][1] = 2.0f * near / (top - bottom);
    projection.m[1][2] = (top + bottom) / ( top - bottom);

    projection.m[2][2] =  -( far + near)/ ( far - near);
    projection.m[2][3] = (-2.0f * far * near) / (far - near);

    projection.m[3][2] = -1;

    return projection;
}

Camera& Camera::set_top(float top) {
    this->top = top;
    return *this;
}

Camera& Camera::set_bottom(float bottom) {
    this->bottom = bottom;
    return *this;
}

Camera& Camera::set_left(float left) {
    this->left = left;
    return *this;
}

Camera& Camera::set_right(float right) {
    this->right = right;
    return *this;
}

Camera& Camera::set_near(float near) {
    this->near = near;
    return *this;
}

Camera& Camera::set_far(float far) {
    this->far = far;
    return *this;
}

Camera& Camera::set_focal(float focal) {
    this->focal = focal;
    return *this;
}

float Camera::get_top() {
    return top;
}

float Camera::get_bottom() {
    return bottom;
}

float Camera::get_left() {
    return left;
}

float Camera::get_right() {
    return right;
}

float Camera::get_near() {
    return near;
}

float Camera::get_far() {
    return far;
}

float Camera::get_focal() {
    return focal;
}
