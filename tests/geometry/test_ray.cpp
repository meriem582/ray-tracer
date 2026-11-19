#include "geometry/ray.h"
#include "test_helpers.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Ray returns its origin and direction") {
    const Ray ray(Vector(1, 2, 3), Vector(3, 4, 0));

    requireVectorsEqual(ray.origin(), Vector(1, 2, 3));
    requireVectorsEqual(ray.direction(), Vector(3, 4, 0));
}
