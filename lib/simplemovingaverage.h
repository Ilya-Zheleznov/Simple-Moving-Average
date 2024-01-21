#include <vector>
#include <algorithm>
#include <cassert>
#include <stdexcept>

namespace SMA {
	static double computeFirstAverage(const std::vector<double> &arr, unsigned k);
	static float computeFirstAverage(const std::vector<float> &arr, unsigned k);
	double simpleMovingAverage (const std::vector<double> &arr, unsigned k);
	float simpleMovingAverage (const std::vector<float> &arr, unsigned k);
}
