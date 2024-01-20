#include <iostream>
#include <ctime>
#include <chrono>

#include "simplemovingaverage.h"

int main(){
    std::srand(unsigned(std::time(nullptr)));
    std::vector<double> v(1000000);
    std::generate(v.begin(), v.end(), std::rand);

    // std::vector<float> v2(1000000);
    // std::generate(v2.begin(), v2.end(), std::rand);

    auto now = std::chrono::high_resolution_clock::now();
    SMA::simpleMovingAverage(v, 1000000);
    auto then = std::chrono::high_resolution_clock::now();
    auto dur = then - now;
    std::cout << std::chrono::duration<double>(dur).count() << std::endl;
    
    return 0;
}
