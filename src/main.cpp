#include "color.h"
#include "vec3.h"
#include <iostream>
#include <print>

int main() {
    size_t image_width = 256;
    size_t image_height = 256;

    std::println("P3");
    std::println("{} {}", image_width, image_height);
    std::println("255");

    for (size_t j = 0; j < image_height; j++) {
        std::print(stderr, "\rScanlines remaining: {:<5}", image_height - j);
        for (size_t i = 0; i < image_width; i++) {
            auto pixel_color =
                color(double(i) / (image_width - 1), double(j) / (image_height - 1), 0);
            write_color(std::cout, pixel_color);
        }
    }
    std::println(stderr, "\rDone.                   ");
}
