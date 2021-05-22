#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>

#include "vector.hpp"

constexpr int width = 1024;
constexpr int height = 768;

static int write_to_ppm(std::vector<vec3> framebuffer)
{
    std::fstream file;
    file.open("example.ppm", std::ios::out | std::ios::binary);
    if(!file.is_open()) {
        std::cerr << "File not opened" << std::endl;
        return -1;
    }

    file << "P6\n" << width << " " << height << "\n255\n";
    for(std::size_t i = 0; i < framebuffer.size(); i++)
        for(std::size_t j = 0; j < 3; j++)
            file << (char)(255 * std::max(0.f, std::min(1.f, framebuffer[i][j])));
    return 0;
}

int main(int argc, char **argv)
{
    std::vector<vec3> framebuffer(width * height);
    for (size_t j = 0; j<height; j++) {
        for (size_t i = 0; i<width; i++) {
            framebuffer[i+j*width] = vec3(j/float(height),i/float(width), 0);
        }
    }
    write_to_ppm(framebuffer);
    return 0;
}
