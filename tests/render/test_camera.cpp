#include "render/camera.h"
#include "test_helpers.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Camera ray passes through the screen centre") {
    const Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 2);
    const Ray ray = camera.rayThroughPixel(0, 0, 1, 1);

    requireVectorsEqual(ray.origin(), Vector(0, 0, -1));
    requireVectorsEqual(ray.direction(), Vector(0, 0, 1));
}

TEST_CASE("Camera ray uses the screen centre minus the eye") {
    const Camera camera(Vector(1, 2, -1), Vector(4, 6, -1), 2);
    const Ray ray = camera.rayThroughPixel(0, 0, 1, 1);

    requireVectorsEqual(ray.origin(), Vector(1, 2, -1));
    requireVectorsEqual(ray.direction(), Vector(3, 4, 0));
}

TEST_CASE("Camera ray passes through the centre pixel") {
    const Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 5);
    const Ray ray = camera.rayThroughPixel(2, 1, 5, 3);

    requireVectorsEqual(ray.origin(), Vector(0, 0, -1));
    requireVectorsEqual(ray.direction(), Vector(0, 0, 1));
}

TEST_CASE("Camera ray passes through the top-right pixel") {
    const Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 5);
    const Ray ray = camera.rayThroughPixel(4, 0, 5, 3);

    requireVectorsEqual(ray.origin(), Vector(0, 0, -1));
    requireVectorsEqual(ray.direction(), Vector(2, 1, 1));
}

TEST_CASE("Camera ray passes through the bottom-left pixel") {
    const Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 5);
    const Ray ray = camera.rayThroughPixel(0, 2, 5, 3);

    requireVectorsEqual(ray.origin(), Vector(0, 0, -1));
    requireVectorsEqual(ray.direction(), Vector(-2, -1, 1));
}

TEST_CASE("Camera renders a red plus") {
    const Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 5);
    const Sphere sphere(Vector(0, 0, 6), 5, Colour(1, 0, 0));
    const Image image = camera.render(sphere, 5, 3);

    REQUIRE(image.width() == 5);
    REQUIRE(image.height() == 3);

    const Colour red(1, 0, 0);
    const Colour black(0, 0, 0);

    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 5; ++column) {
            const bool shouldBeRed = column == 2 || (row == 1 && (column == 1 || column == 3));
            requireColoursEqual(image.pixel(column, row), shouldBeRed ? red : black);
        }
    }
}
