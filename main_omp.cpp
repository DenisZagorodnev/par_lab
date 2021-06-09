#include <vector>
#include <iostream>
#include <omp.h>
#include "defs.h"
#include <math.h>
#include <fstream>

const int num_repetitions = 10;

int main(int argc, const char *argv[]) {

    size_t N = (size_t) powl(10, 7);
    std::vector<float> arr(N);
    std::vector<int> num_threads{1, 2, 4, 8, 16};
    std::ofstream myfile;

    myfile.open ("res_omp.csv");
    myfile << "num_thread" << ',' <<  "fill_duration" << ',' << "resample_duration" << std::endl;
    for(auto const& num_thread: num_threads) {
        omp_set_num_threads(num_thread);
        float fill_duration = time_call(num_repetitions, [&]() {
            fill_up_vector( std::ref(arr), 0, arr.size());
        });


        float resample_duration = time_call(num_repetitions, [&]() {
            resample_vector(arr, 0, arr.size(), arr[0]);
        });

        std::cout << num_thread << ',' <<  fill_duration << ',' << resample_duration << std::endl;
        myfile << num_thread << ',' <<  fill_duration << ',' << resample_duration << std::endl;
    }

    myfile.close();
    return 0;
}
