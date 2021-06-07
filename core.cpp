#include <vector>
#include <iostream>
#include "defs.h"

int rand_val = 1;

int rand() {
    int ret = rand_val;
    rand_val++;
    return ret;
}

void fill_up_vector(std::vector<float> &arr, long from, long to) {
    std::cout << "filling up array from " << from << " to " << to << std::endl;

    #pragma omp parallel for
    for (long i = from; i < to; i++) {
        arr[i] = (float) rand();
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
