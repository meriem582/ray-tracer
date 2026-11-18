#include "raytracer/greeting.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("greeting returns the demo message") {
    REQUIRE(raytracer::greeting() == "Hello, World!");
}
