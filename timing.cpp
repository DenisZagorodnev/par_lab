#include <ctime>
#include <vector>
#include <iostream>
#include <limits>
#include "defs.h"

void time_call(int reps, std::function<void(void)> func) {
    /*почему?*/
    double min_duration = std::numeric_limits<float>::max();
    for (int i = 0; i < reps; i++) {
        std::cout << "iteration " << i << std::endl;
        clock_t begin = clock();

        func();

        clock_t end = clock();
        double elapsed_secs = (double) (end - begin) / CLOCKS_PER_SEC;
        std::cout << "iteration " << i << " elapsed time " << elapsed_secs << std::endl;
        if (elapsed_secs < min_duration) {
            min_duration = elapsed_secs;
        }
    }

    std::cout << "minimal elapsed time" << min_duration << std::endl;
}
