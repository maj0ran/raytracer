#include "sphere.hpp"
#include <math.h>

Sphere::Sphere(const vec3 &center, const float radius) :
    center_(center), radius_(radius)
{
}

Sphere::~Sphere()
{
}

bool Sphere::intersect(Ray &r)
{   
    /* alias to shorten the mathematical lines */
    vec3 &r_o = r.origin_;
    vec3 &r_d = r.direction_;
    vec3 &s_c = this->center_;
    float &s_r = this->radius_;

    float t0;
    vec3 L = s_c - r_o;
    float tca = dot(L, r_d);
    float d2 = dot(L,L) - tca*tca;
    if (d2 > s_r * s_r) return false;
    float thc = sqrtf(s_r * s_r - d2);
    t0       = tca - thc;
    float t1 = tca + thc;
    if (t0 < 0) t0 = t1;
    if (t0 < 0) return false;
    return true;
}
