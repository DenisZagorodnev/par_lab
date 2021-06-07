#include <vector>
#include <iostream>
#include <omp.h>
#include "defs.h"
#include <math.h>


const int num_repetitions = 10;
const int num_threads = 1;

int main(int argc, const char *argv[]) {
    size_t N = (size_t) powl(10, 7);

    std::vector<float> arr(N);

    omp_set_num_threads(num_threads);

    time_call(num_repetitions, [&] () {
        fill_up_vector(arr, 0, arr.size());
    });

    return 0;
}
