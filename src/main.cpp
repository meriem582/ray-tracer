#include "geometry/sphere.h"
#include "image/image.h"
#include "math/vector.h"
#include "output/png_saver.h"
#include "render/camera.h"

#include <iostream>
#include <string>

int main() {
    const Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 2);
    const Sphere sphere(Vector(0, 0, 9), 5, Material(Colour(1, 0, 0)));
    const Vector toLight = Vector(-1, 1, -1).normalised();
    const Image image = camera.render(sphere, toLight, 400, 300);
    const std::string path = "image.png";

    const PngSaver saver;
    saver.save(image, path);

    std::cout << path << "\n";
    return 0;
}
