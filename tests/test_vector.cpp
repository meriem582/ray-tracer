#include "vector.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("operator+ adds each coordinate") {
    const Vector first(3, 4, 0);
    const Vector second(4, -3, 0);
    const Vector sum = first + second;

    REQUIRE(sum.x() == 7);
    REQUIRE(sum.y() == 1);
    REQUIRE(sum.z() == 0);
}

TEST_CASE("operator+ adds nonzero z coordinates") {
    const Vector first(3, 4, 1);
    const Vector second(4, -3, 2);
    const Vector sum = first + second;

    REQUIRE(sum.x() == 7);
    REQUIRE(sum.y() == 1);
    REQUIRE(sum.z() == 3);
}

TEST_CASE("operator- subtracts vectors with zero z coordinates") {
    const Vector first(4, 5, 0);
    const Vector second(1, 1, 0);
    const Vector difference = first - second;

    REQUIRE(difference.x() == 3);
    REQUIRE(difference.y() == 4);
    REQUIRE(difference.z() == 0);
}

TEST_CASE("operator- subtracts nonzero z coordinates") {
    const Vector first(4, 5, 6);
    const Vector second(1, 1, 2);
    const Vector difference = first - second;

    REQUIRE(difference.x() == 3);
    REQUIRE(difference.y() == 4);
    REQUIRE(difference.z() == 4);
}

TEST_CASE("scalar multiplication scales each coordinate") {
    const Vector vector(3, -4, 1);
    const Vector scaled = 2.0 * vector;

    REQUIRE(scaled.x() == 6);
    REQUIRE(scaled.y() == -8);
    REQUIRE(scaled.z() == 2);
}

TEST_CASE("ray equation computes O plus t times D") {
    const Vector O(0, 8, 0);
    const Vector D(3, -4, 0);
    const double t = 2;
    const Vector point = O + t * D;

    REQUIRE(point.x() == 6);
    REQUIRE(point.y() == 0);
    REQUIRE(point.z() == 0);
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
