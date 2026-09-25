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
            auto r = double(i) / (image_width - 1);
            auto g = double(j) / (image_height - 1);
            auto b = 0.0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            std::println("{} {} {}", ir, ig, ib);
        }
    }
    std::println(stderr, "\rDone.                   ");
}
