#pragma once

#include "material/material.h"
#include "math/vector.h"

struct Hit {
    double t;
    Vector point;
    Vector normal;
    Material material;
};
