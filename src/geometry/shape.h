#pragma once

#include "geometry/hit.h"
#include "geometry/ray.h"

#include <optional>

class Shape {
public:
    virtual ~Shape() = default;

    // Every shape gives its nearest hit in front of the ray's origin, with t > 0 and a unit normal, or nothing.
    virtual std::optional<Hit> hit(const Ray& ray) const = 0;
};
