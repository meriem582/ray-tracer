#include "geometry/ray.h"
#include "test_helpers.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Ray returns its origin and direction") {
    const Ray ray(Vector(1, 2, 3), Vector(3, 4, 0));

    requireVectorsEqual(ray.origin(), Vector(1, 2, 3));
    requireVectorsEqual(ray.direction(), Vector(3, 4, 0));
}

TEST_CASE("Ray gives the point at parameter t") {
    const Ray ray(Vector(0, 8, 0), Vector(3, -4, 0));

    requireVectorsEqual(ray.at(0), Vector(0, 8, 0));
    requireVectorsEqual(ray.at(2), Vector(6, 0, 0));
}
