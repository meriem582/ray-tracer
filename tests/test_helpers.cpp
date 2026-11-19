#include "test_helpers.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

const double tolerance = 1e-9;

void requireColoursEqual(const Colour& actual, const Colour& expected) {
    REQUIRE_THAT(actual.r(), Catch::Matchers::WithinAbs(expected.r(), tolerance));
    REQUIRE_THAT(actual.g(), Catch::Matchers::WithinAbs(expected.g(), tolerance));
    REQUIRE_THAT(actual.b(), Catch::Matchers::WithinAbs(expected.b(), tolerance));
}

void requireVectorsEqual(const Vector& actual, const Vector& expected) {
    REQUIRE_THAT(actual.x(), Catch::Matchers::WithinAbs(expected.x(), tolerance));
    REQUIRE_THAT(actual.y(), Catch::Matchers::WithinAbs(expected.y(), tolerance));
    REQUIRE_THAT(actual.z(), Catch::Matchers::WithinAbs(expected.z(), tolerance));
}
