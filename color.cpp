#include "color.h"

Color::Color() {
    r = 0;
    g = 0;
    b = 0;
    a = 0;
}

Color::Color(int r, int g, int b) {
    this->r = r;
    this->g = g;
    this->b = b;
    a = 0;
}

Color::Color(int r, int g, int b, int a) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

Color Color::operator*(const float& scale) const {
    return Color(r * scale, g * scale, b * scale, a * scale);
}

Color Color::operator+(const Color& rhs) const {
    return Color( r + rhs.r, g + rhs.g, b + rhs.b, a + rhs.a);
}
