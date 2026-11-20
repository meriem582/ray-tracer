#include "render/trace.h"
#include "test_helpers.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("trace returns the sphere colour when the ray hits") {
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(Vector(0, 0, 9), 5, Material(Colour(1, 0, 0)));

    requireColoursEqual(trace(ray, sphere), Colour(1, 0, 0));
}

TEST_CASE("trace returns black when the ray misses") {
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(Vector(6, 0, 9), 5, Material(Colour(1, 0, 0)));

    requireColoursEqual(trace(ray, sphere), Colour(0, 0, 0));
}
