#include "material/material.h"
#include "test_helpers.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Material returns its colour") {
    const Material material(Colour(1, 0.5, 0));

    requireColoursEqual(material.colour(), Colour(1, 0.5, 0));
}

TEST_CASE("Material returns its full colour when facing the light") {
    const Material material(Colour(1, 0.5, 0));

    requireColoursEqual(
        material.shade(Vector(0, 0, -1), Vector(0, 0, -1)),
        Colour(1, 0.5, 0));
}

TEST_CASE("Material scales its colour by the angle to the light") {
    const Material material(Colour(1, 0.5, 0));

    requireColoursEqual(
        material.shade(Vector(0, 0, -1), Vector(0.6, 0, -0.8)),
        Colour(0.8, 0.4, 0));
}

TEST_CASE("Material returns black when the surface is perpendicular to the light") {
    const Material material(Colour(1, 0.5, 0));

    requireColoursEqual(
        material.shade(Vector(0, 0, -1), Vector(1, 0, 0)),
        Colour(0, 0, 0));
}

TEST_CASE("Material returns black when the surface faces away from the light") {
    const Material material(Colour(1, 0.5, 0));

    requireColoursEqual(
        material.shade(Vector(0, 0, -1), Vector(0, 0, 1)),
        Colour(0, 0, 0));
}
