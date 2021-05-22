#pragma once

#include "vector.hpp"

class Ray {
    public:
        Ray(const vec3 &origin, const vec3 &direction); 
        ~Ray();

        vec3 origin_;
        vec3 direction_;
};
