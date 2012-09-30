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
