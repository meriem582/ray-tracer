#include "colour/colour.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Colour returns its channels") {
    const Colour colour(1, 0.5, 0);

    REQUIRE(colour.r() == 1);
    REQUIRE(colour.g() == 0.5);
    REQUIRE(colour.b() == 0);
}

TEST_CASE("scalar multiplication scales every colour channel") {
    const Colour colour = 0.5 * Colour(1, 0.5, 0);

    REQUIRE(colour.r() == 0.5);
    REQUIRE(colour.g() == 0.25);
    REQUIRE(colour.b() == 0);
}
