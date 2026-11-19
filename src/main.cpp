#include "colour/colour.h"
#include "geometry/sphere.h"
#include "render/camera.h"

#include <iostream>

int main() {
    const Camera camera(Vector(0, 0, -1), Vector(0, 0, 0));
    const Sphere sphere(Vector(0, 0, 9), 5, Colour(1, 0, 0));
    const Ray ray = camera.rayThroughCentre();
    const Colour pixel = sphere.isHitBy(ray) ? sphere.colour() : Colour(0, 0, 0);

    std::cout << "(" << pixel.r() << ", " << pixel.g() << ", " << pixel.b() << ")\n";
    return 0;
}
