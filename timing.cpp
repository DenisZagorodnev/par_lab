#include <ctime>
#include <vector>
#include <iostream>
#include <limits>
#include "defs.h"
#include <fstream>

float time_call(int reps, std::function<void(void)> func) {

    double min_duration = std::numeric_limits<float>::max();
    for (int i = 0; i < reps; i++) {
        clock_t begin = clock();
        func();
        clock_t end = clock();
        double elapsed_secs = (double) (end - begin) / CLOCKS_PER_SEC;

        if (elapsed_secs < min_duration) {
            min_duration = elapsed_secs;
        }
    }
    return min_duration;
}
