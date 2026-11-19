#pragma once

#include "colour.h"
#include "math/vector.h"
#include "ray.h"

class Sphere {
public:
    Sphere(const Vector& centre, double radius, const Colour& colour);

    Colour colour() const;
    bool isHitBy(const Ray& ray) const;

private:
    Vector _centre;
    double _radius;
    Colour _colour;
};
