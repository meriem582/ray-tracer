#include "image/image.h"
#include "test_helpers.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("setting a pixel changes only that pixel", "[image]") {
    Image image(5, 3);

    REQUIRE(image.width() == 5);
    REQUIRE(image.height() == 3);

    const Colour black(0, 0, 0);
    const Colour red(1, 0, 0);

    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 5; ++column) {
            requireColoursEqual(image.pixel(column, row), black);
        }
    }

    image.setPixel(4, 0, red);

    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 5; ++column) {
            if (column == 4 && row == 0) {
                requireColoursEqual(image.pixel(column, row), red);
            } else {
                requireColoursEqual(image.pixel(column, row), black);
            }
        }
    }
}
