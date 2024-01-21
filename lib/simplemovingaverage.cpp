#include "simplemovingaverage.h"

double SMA::computeFirstAverage(const std::vector<double> &arr, unsigned k){
    double sum{};
    std::for_each(arr.begin(), arr.begin() + k, [&](double val){
	    sum += val;
    });
    double firstSMA = sum / k;
    return firstSMA;
}

float SMA::computeFirstAverage(const std::vector<float> &arr, unsigned k){
    float sum{};
    std::for_each(arr.begin(), arr.begin() + k, [&](float val){
	    sum += val;
    });
    float firstSMA = sum / k;
    return firstSMA;
}

double SMA::simpleMovingAverage (const std::vector<double> &arr, unsigned k){
    assert(k > 1 && "Window length is invalid");
    if(arr.size() == 0){
        return 0;
    }
    else if(arr.size() == 1){
        return arr.at(0);
    }
    else if(arr.size() < k){
        throw "Window length is too large";
    }

    unsigned offset{1};
    double currentSMA{ computeFirstAverage(arr, k) };
    double nextSMA{};
    double sumSMAs{ currentSMA };
    double averageNumber;
    while(arr.begin() + offset + k != arr.end() + 1){
        nextSMA = currentSMA + (*(arr.begin() + offset + k - 1) - *(arr.begin() + offset - 1)) / k;
        sumSMAs += nextSMA;
        currentSMA = nextSMA;
        offset++;
    }
    averageNumber = sumSMAs / offset;
    return averageNumber;
}

float SMA::simpleMovingAverage (const std::vector<float> &arr, unsigned k){
    assert(k > 1 && "Window length is invalid");
    assert(k > 1 && "Window length is invalid");
    if(arr.size() == 0){
        return 0;
    }
    else if(arr.size() == 1){
        return arr.at(0);
    }
    else if(arr.size() < k){
        throw "Window length is too large";
    }
    
    unsigned offset{1};
    float currentSMA{ computeFirstAverage(arr, k) };
    float nextSMA{};
    float sumSMAs{ currentSMA };
    float averageNumber;
    while(arr.begin() + offset + k != arr.end() + 1){
        nextSMA = currentSMA + (*(arr.begin() + offset + k - 1) - *(arr.begin() + offset - 1)) / k;
        sumSMAs += nextSMA;
        currentSMA = nextSMA;
        offset++;
    }
    averageNumber = sumSMAs / offset;
    return averageNumber;
}

