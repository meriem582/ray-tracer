#pragma once

#include "math/vector.h"
#include "ray.h"

class Camera {
public:
    Camera(const Vector& eye, const Vector& screenCentre);

    Ray rayThroughCentre() const;

private:
    Vector _eye;
    Vector _screenCentre;
};
