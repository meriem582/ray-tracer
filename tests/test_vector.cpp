#include "vector.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("adding vectors adds each coordinate") {
    const Vector first(3, 4, 0);
    const Vector second(4, -3, 0);
    const Vector sum = first.add(second);

    REQUIRE(sum.x() == 7);
    REQUIRE(sum.y() == 1);
    REQUIRE(sum.z() == 0);
}
