#include <iostream>
#include <ctime>
#include <chrono>

#include "simplemovingaverage.h"

int main(){
    std::srand(unsigned(std::time(nullptr)));

    std::vector<double> v1(1000000);
    std::generate(v1.begin(), v1.end(), std::rand);

    std::vector<float> v2(1000000);
    std::generate(v2.begin(), v2.end(), std::rand);

    for(int k = 4; k < 256; k *= 2){
        auto now1 = std::chrono::high_resolution_clock::now();
        SMA::simpleMovingAverage(v1, k);
        auto then1 = std::chrono::high_resolution_clock::now();
        auto dur1 = then1 - now1;
        std::cout << "Execution time(double) for " << k << " window size is " << std::chrono::duration<double>(dur1).count() << std::endl;
        
        auto now2 = std::chrono::high_resolution_clock::now();
        SMA::simpleMovingAverage(v2, k);
        auto then2 = std::chrono::high_resolution_clock::now();
        auto dur2 = then2 - now2;
        std::cout << "Execution time(float) for " << k << " window size is " << std::chrono::duration<double>(dur2).count() << std::endl << std::endl;
    }
    
    return 0;
}
