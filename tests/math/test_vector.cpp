#include "math/vector.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

const double tolerance = 1e-9;

static void requireVectorsEqual(const Vector& actual, const Vector& expected) {
    REQUIRE_THAT(actual.x(), Catch::Matchers::WithinAbs(expected.x(), tolerance));
    REQUIRE_THAT(actual.y(), Catch::Matchers::WithinAbs(expected.y(), tolerance));
    REQUIRE_THAT(actual.z(), Catch::Matchers::WithinAbs(expected.z(), tolerance));
}

TEST_CASE("operator+ adds each coordinate") {
    const Vector first(3, 4, 0);
    const Vector second(4, -3, 0);
    const Vector sum = first + second;

    requireVectorsEqual(sum, Vector(7, 1, 0));
}

TEST_CASE("operator+ adds nonzero z coordinates") {
    const Vector first(3, 4, 1);
    const Vector second(4, -3, 2);
    const Vector sum = first + second;

    requireVectorsEqual(sum, Vector(7, 1, 3));
}

TEST_CASE("operator- subtracts vectors with zero z coordinates") {
    const Vector first(4, 5, 0);
    const Vector second(1, 1, 0);
    const Vector difference = first - second;

    requireVectorsEqual(difference, Vector(3, 4, 0));
}

TEST_CASE("operator- subtracts nonzero z coordinates") {
    const Vector first(4, 5, 6);
    const Vector second(1, 1, 2);
    const Vector difference = first - second;

    requireVectorsEqual(difference, Vector(3, 4, 4));
}

TEST_CASE("scalar multiplication scales each coordinate") {
    const Vector vector(3, -4, 1);
    const Vector scaled = 2.0 * vector;

    requireVectorsEqual(scaled, Vector(6, -8, 2));
}

TEST_CASE("ray equation computes O plus t times D") {
    const Vector O(0, 8, 0);
    const Vector D(3, -4, 0);
    const double t = 2;
    const Vector point = O + t * D;

    requireVectorsEqual(point, Vector(6, 0, 0));
}

TEST_CASE("dot product multiplies and sums matching coordinates") {
    const Vector first(3, 4, 0);
    const Vector second(4, 3, 0);

    REQUIRE(first.dot(second) == 24);
}

TEST_CASE("dot product is zero for perpendicular vectors") {
    const Vector first(3, 4, 0);
    const Vector second(4, -3, 0);

    REQUIRE(first.dot(second) == 0);
}

TEST_CASE("dot product includes nonzero z coordinates") {
    const Vector first(3, 4, 12);
    const Vector second(4, 3, 1);

    REQUIRE(first.dot(second) == 36);
}

TEST_CASE("length returns the vector magnitude") {
    const Vector vector(3, -4, 0);

    REQUIRE(vector.length() == 5);
}

TEST_CASE("length includes nonzero z coordinates") {
    const Vector vector(3, 4, 12);

    REQUIRE(vector.length() == 13);
}

TEST_CASE("normalised returns a unit vector in the same direction") {
    const Vector vector(3, -4, 0);
    const Vector unit = vector.normalised();

    requireVectorsEqual(unit, Vector(0.6, -0.8, 0));
}

TEST_CASE("normalised vector has length one") {
    const Vector vector(3, 4, 12);

    REQUIRE_THAT(vector.normalised().length(), Catch::Matchers::WithinAbs(1, tolerance));
}
