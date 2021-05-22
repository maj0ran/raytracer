#include "ray.hpp"

Ray::Ray(const vec3 &origin, const vec3 &direction) : 
    origin_(origin), direction_(direction)
{
}

Ray::~Ray()
{
}
