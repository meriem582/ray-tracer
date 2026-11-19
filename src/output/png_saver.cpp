#include "output/png_saver.h"

#include "colour/colour.h"

#include <lodepng.h>

#include <cmath>
#include <stdexcept>
#include <vector>

static unsigned char toByte(double value) {
    return static_cast<unsigned char>(std::lround(value * 255));
}

void PngSaver::save(const Image& image, const std::string& path) const {
    std::vector<unsigned char> bytes;

    for (int row = 0; row < image.height(); ++row) {
        for (int column = 0; column < image.width(); ++column) {
            const Colour colour = image.pixel(column, row);
            bytes.push_back(toByte(colour.r()));
            bytes.push_back(toByte(colour.g()));
            bytes.push_back(toByte(colour.b()));
        }
    }

    const unsigned error =
        lodepng::encode(path, bytes, image.width(), image.height(), LCT_RGB);
    if (error != 0) {
        throw std::runtime_error(lodepng_error_text(error));
    }
}
