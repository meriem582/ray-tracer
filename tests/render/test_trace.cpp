#include "render/trace.h"
#include "test_helpers.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("trace returns the sphere colour when the hit faces the light") {
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(Vector(0, 0, 9), 5, Material(Colour(1, 0, 0)));

    requireColoursEqual(
        trace(ray, sphere, Vector(0, 0, -1)),
        Colour(1, 0, 0));
}

TEST_CASE("trace dims the sphere when the light is at an angle") {
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(Vector(0, 0, 9), 5, Material(Colour(1, 0, 0)));

    requireColoursEqual(
        trace(ray, sphere, Vector(0.6, 0, -0.8)),
        Colour(0.8, 0, 0));
}

TEST_CASE("trace shades an off-centre hit using its normal") {
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(Vector(3, 0, 9), 5, Material(Colour(1, 0, 0)));

    requireColoursEqual(
        trace(ray, sphere, Vector(0, 0, -1)),
        Colour(0.8, 0, 0));
}

TEST_CASE("trace returns black when the ray misses") {
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(Vector(6, 0, 9), 5, Material(Colour(1, 0, 0)));

    requireColoursEqual(
        trace(ray, sphere, Vector(0, 0, -1)),
        Colour(0, 0, 0));
}
