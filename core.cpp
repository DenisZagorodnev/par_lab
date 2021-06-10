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

float get_my_random() {
    static float r = 0;
    r += 1;
    return r;
}

void fill_up_vector(std::vector<float> &arr, long from, long to) {

#pragma omp parallel for
    for (long i = from; i < to; i++) {
        arr[i] = get_my_random();
    }

}


void resample_vector(std::vector<float> &arr, long from, long to, float next) {

#pragma omp parallel for
    for (long i = from; i < to - 1; i++) {
        arr[i] = arr[i] + arr[i + 1];
    }
    arr[to - 1] = next + arr[to - 1];
}


void print_array(std::vector<float> &arr) {

    if (arr.size() > 20) {
        return;
    }
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}
