#include "geometry/sphere.h"

#include <cmath>

Sphere::Sphere(const Vector& centre, double radius, const Material& material)
    : _centre(centre), _radius(radius), _material(material) {}

Colour Sphere::colour() const {
    return _material.colour();
}

bool Sphere::isHitBy(const Ray& ray) const {
    Vector O = ray.origin();
    Vector D = ray.direction();
    Vector C = _centre;
    Vector L = O - C;
    double a = D.dot(D);
    double b = 2.0 * D.dot(L);
    double c = L.dot(L) - _radius * _radius;
    double discriminant = b * b - 4.0 * a * c;
    if (discriminant < 0.0) {
        return false;
    }

    double root = std::sqrt(discriminant);
    double t1 = (-b - root) / (2.0 * a);
    double t2 = (-b + root) / (2.0 * a);
    return t1 > 0.0 || t2 > 0.0;
}
