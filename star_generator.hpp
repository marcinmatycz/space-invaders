#pragma once
#include "raylib.h"
#include <array>
#include <random>

struct Star {
    Vector2 v1{};
    Vector2 v2{};
    Vector2 v3{};
    Color color{RAYWHITE};
};

template <unsigned int width, unsigned int height>
std::array<Star, (width / 100) * (height / 100) + 2> generate_stars_background() {
    // evenly spaced little triangles with various opacity for now
    // constexpr unsigned int block_area
    // const auto number_of_blocks{width * height/1000};
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_real_distribution<> dist(1.f,100.f);

    std::array<Star, (width / 100) * (height / 100) + 2> star_array{};
    float column{0};
    float row{0};

    for(auto &star : star_array) {
        const float rx = static_cast<float>(dist(rng));
        const float ry = static_cast<float>(dist(rng));

        star.v1 = {10.f+column+rx, 5.f+row+ry};
        star.v2 = {5.f+column+rx, 10.f+row+ry};
        star.v3 = {10.f+column+rx, 10.f+row+ry};

        column += 100.f;
        if(column > width) {
            row += 100.f;
            column = 0.f;
        } 
    }
    return star_array;
}