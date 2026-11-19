#include "render/camera.h"
#include "test_helpers.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Camera ray passes through the screen centre") {
    const Camera camera(Vector(0, 0, -1), Vector(0, 0, 0));
    const Ray ray = camera.rayThroughCentre();

    requireVectorsEqual(ray.origin(), Vector(0, 0, -1));
    requireVectorsEqual(ray.direction(), Vector(0, 0, 1));
}

TEST_CASE("Camera ray uses the screen centre minus the eye") {
    const Camera camera(Vector(1, 2, -1), Vector(4, 6, -1));
    const Ray ray = camera.rayThroughCentre();

    requireVectorsEqual(ray.origin(), Vector(1, 2, -1));
    requireVectorsEqual(ray.direction(), Vector(3, 4, 0));
}
