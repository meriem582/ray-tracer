#include "geometry/plane.h"
#include "geometry/sphere.h"
#include "image/image.h"
#include "math/vector.h"
#include "output/png_saver.h"
#include "render/camera.h"
#include "scene/scene.h"

#include <iostream>
#include <memory>
#include <string>

int main() {
    const Camera camera(Vector(0, 0, -1), Vector(0, 0, 0), 2);
    Scene scene(Vector(-1, 1, -1));
    scene.add(std::make_unique<Sphere>(
        Vector(0, 0, 9), 5, Material(Colour(1, 0, 0))));
    scene.add(std::make_unique<Plane>(
        Vector(0, -5, 0), Vector(0, 1, 0), Material(Colour(0.8, 0.8, 0.8))));
    const Image image = camera.render(scene, 400, 300);
    const std::string path = "image.png";

    const PngSaver saver;
    saver.save(image, path);

    std::cout << path << "\n";
    return 0;
}
