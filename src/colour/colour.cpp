#include "colour/colour.h"

Colour::Colour(double r, double g, double b) : _r(r), _g(g), _b(b) {}

double Colour::r() const {
    return _r;
}

double Colour::g() const {
    return _g;
}

double Colour::b() const {
    return _b;
}

Colour operator*(double scalar, const Colour& colour) {
    return Colour(
        scalar * colour.r(),
        scalar * colour.g(),
        scalar * colour.b());
}
