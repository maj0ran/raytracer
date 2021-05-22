#pragma once

#include "vector.hpp"

#include "ray.hpp"

class Sphere {
    public:
        Sphere(const vec3 &center, const float radius);
        ~Sphere();

        vec3 center_;
        float radius_;

        bool intersect(Ray &ray);

};
