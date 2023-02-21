#include <iostream>
#include <algorithm>
#include "Matrix.h"
#include "RandomMatrix.h"
#include <chrono>


int main() {

    RandomMatrix rm(1500);
    auto x = std::chrono::high_resolution_clock::now();
    rm.solve_gauss(std::cin, std::cout);

    auto y = std::chrono::high_resolution_clock::now();
    auto z = std::chrono::duration_cast<std::chrono::milliseconds>(y-x);
    std::cout<<z.count();

}
