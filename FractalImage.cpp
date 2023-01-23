#include <iostream>
#include <complex>
#include <cstdlib>
#include <cstdio>
#include <random>

const int WIDTH = 800;
const int HEIGHT = 600;
const int MAX_ITER = 256;
const double ZOOM = 1;

std::random_device rd;
std::mt19937 engine(rd());
std::uniform_int_distribution<int> dist(0, MAX_ITER-1);

int main() {
    std::complex<double> z, c;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            z = std::complex<double>(0, 0);
            c = std::complex<double>( (x - WIDTH/2) * ZOOM / WIDTH,
                                      (y - HEIGHT/2) * ZOOM / HEIGHT);
            int iteration = 0;
            while (abs(z) < 2 && iteration < MAX_ITER) {
                z = z*z + c;
                iteration++;
            }
            if (iteration < MAX_ITER) {
                // color pixel based on iteration
                int color = dist(engine);
                std::cout << color << " ";
            } else {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
