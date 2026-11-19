#include "geometry/sphere.h"
#include "image/image.h"
#include "math/vector.h"
#include "output/png_saver.h"
#include "render/camera.h"

#include <iostream>
#include <string>

int main() {
    const Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 2);
    const Sphere sphere(Vector(0, 0, 9), 5, Colour(1, 0, 0));
    const Image image = camera.render(sphere, 400, 300);
    const std::string path = "image.png";

    const PngSaver saver;
    saver.save(image, path);

    std::cout << path << "\n";
    return 0;
}
