#include "output/png_saver.h"

#include <catch2/catch_test_macros.hpp>
#include <lodepng.h>

#include <filesystem>
#include <string>
#include <vector>

TEST_CASE("PngSaver writes RGB pixels in row-major order", "[output]") {
    Image image(2, 2);
    image.setPixel(1, 0, Colour(1, 0.5, 0));

    const std::string path = "test_png_saver.png";
    const PngSaver saver;
    saver.save(image, path);

    std::vector<unsigned char> decoded;
    unsigned width = 0;
    unsigned height = 0;
    const unsigned error = lodepng::decode(decoded, width, height, path, LCT_RGB);
    std::filesystem::remove(path);

    REQUIRE(error == 0);
    REQUIRE(width == 2);
    REQUIRE(height == 2);

    const std::vector<int> expected{
        0, 0, 0, 255, 128, 0,
        0, 0, 0, 0, 0, 0
    };
    REQUIRE(decoded.size() == expected.size());

    for (std::size_t index = 0; index < expected.size(); ++index) {
        CHECK(static_cast<int>(decoded[index]) == expected[index]);
    }
}
