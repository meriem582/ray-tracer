#include "geometry/plane.h"
#include "geometry/sphere.h"
#include "scene/scene.h"
#include "test_helpers.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <memory>
#include <optional>

TEST_CASE("Scene finds a nearer plane added after the sphere") {
    Scene scene(Vector(0, 0, -1));
    scene.add(std::make_unique<Sphere>(
        Vector(0, 0, 9), 5, Material(Colour(1, 0, 0))));
    scene.add(std::make_unique<Plane>(
        Vector(0, 0, 2), Vector(0, 0, -1), Material(Colour(0, 0, 1))));
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));

    const std::optional<Hit> hit = scene.nearestHit(ray);

    REQUIRE(hit.has_value());
    REQUIRE_THAT(hit->t, Catch::Matchers::WithinAbs(3, tolerance));
    requireColoursEqual(hit->material.colour(), Colour(0, 0, 1));
    requireVectorsEqual(scene.toLight(), Vector(0, 0, -1));
}

TEST_CASE("Scene keeps the nearer sphere when a farther plane is added after it") {
    Scene scene(Vector(0, 0, -1));
    scene.add(std::make_unique<Sphere>(
        Vector(0, 0, 9), 5, Material(Colour(1, 0, 0))));
    scene.add(std::make_unique<Plane>(
        Vector(0, 0, 20), Vector(0, 0, -1), Material(Colour(0, 0, 1))));
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));

    const std::optional<Hit> hit = scene.nearestHit(ray);

    REQUIRE(hit.has_value());
    REQUIRE_THAT(hit->t, Catch::Matchers::WithinAbs(5, tolerance));
    requireColoursEqual(hit->material.colour(), Colour(1, 0, 0));
}

TEST_CASE("Scene returns no hit when its only sphere is missed") {
    Scene scene(Vector(0, 0, -1));
    scene.add(std::make_unique<Sphere>(
        Vector(6, 0, 9), 5, Material(Colour(1, 0, 0))));
    const Ray ray(Vector(0, 0, -1), Vector(0, 0, 1));

    REQUIRE_FALSE(scene.nearestHit(ray).has_value());
}

TEST_CASE("Scene normalises the direction towards the light") {
    const Scene scene(Vector(0, 3, -4));

    requireVectorsEqual(scene.toLight(), Vector(0, 0.6, -0.8));
}
