#include <vector>
#include <iostream>
#include "defs.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <random>


float get_random() {
    static std::default_random_engine e;
    static std::uniform_real_distribution<> dis(0, 1);
    return dis(e);
}


void fill_up_vector(std::vector<float> &arr, long from, long to) {
    std::cout << "filling up array from " << from << " to " << to << std::endl;


#pragma omp parallel for
    for (long i = from; i < to; i++) {
        arr[i] = get_random();
    }

}


void resample_vector(std::vector<float> &arr, long from, long to) {
    std::cout << "resampling up array from " << from << " to " << to << std::endl;

#pragma omp parallel for
    for (long i = from; i < to; i++) {
        arr[i] = arr[i] + arr[i + 1];
    }
}


void print_array(float *arr, size_t n) {

    if (n > 20) {
        return;
    }
    for (size_t i = 0; i < n; i++) {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }
}
