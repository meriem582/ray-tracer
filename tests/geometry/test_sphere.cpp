#include "colour/colour.h"
#include "geometry/ray.h"
#include "geometry/sphere.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Sphere is hit when centred on the ray") {
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(Vector(0, 0, 9), 5, Colour(1, 0, 0));

    REQUIRE(sphere.isHitBy(ray));
}

TEST_CASE("Sphere is hit when its centre is three units off the ray") {
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(Vector(3, 0, 9), 5, Colour(1, 0, 0));

    REQUIRE(sphere.isHitBy(ray));
}

TEST_CASE("Sphere is missed when its centre is six units off the ray") {
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));
    const Sphere sphere(Vector(6, 0, 9), 5, Colour(1, 0, 0));

    REQUIRE_FALSE(sphere.isHitBy(ray));
}

TEST_CASE("Sphere returns its colour") {
    const Sphere sphere(Vector(0, 0, 9), 5, Colour(1, 0.5, 0));
    const Colour colour = sphere.colour();

    REQUIRE(colour.r() == 1);
    REQUIRE(colour.g() == 0.5);
    REQUIRE(colour.b() == 0);
}
