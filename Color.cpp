#include "Color.hpp"

Color::Color(int red, int green, int blue) : r(red), g(green), b(blue) {}

bool Color::operator==(const Color& other) const {
    return r == other.r && g == other.g && b == other.b;
}
