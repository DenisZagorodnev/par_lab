#include <cstdlib>
#include <cstdio>
#include <math.h>
#include <ctime>
#include <thread>
#include <vector>
#include <iostream>
#include <limits>
#include "defs.h"

const int num_repetitions = 3;
const int num_threads = 1;

// Сгенерировать линейный массив случайных чисел a[] типа float. Размер массива N=10**9 чисел.
void fill_up_threaded(std::vector<float> &arr, int num_threads) {
    std::vector<std::thread> threads;

    long bunch_size = (arr.size() + num_threads - 1) / num_threads;
    for (int i = 0; i < num_threads; i++) {
        long from = bunch_size * i;
        long to = bunch_size * (i + 1);
        if (to > arr.size()) {
            to = arr.size();
        }
        threads.push_back(std::thread(fill_up_vector, std::ref(arr), from, to));
    }

    for (auto &th : threads) {
        th.join();
    }
}


void resample_threaded(std::vector<float> &arr, int num_threads) {
    std::vector<std::thread> threads;

    long bunch_size = (arr.size() - 1 + num_threads - 1) / num_threads;
    float first = arr[0];



    for (int i = 0; i < num_threads; i++) {
        long from = bunch_size * i;
        long to = bunch_size * (i + 1);
        if (to > arr.size()) {
            to = arr.size();
        }
        threads.push_back(std::thread(resample_vector, std::ref(arr), from, to));
    }

    arr[arr.size() - 1] = arr[arr.size() - 1] + first;
    for (auto &th : threads) {
        th.join();
    }
}


int main(int argc, const char *argv[]) {
    size_t N = (size_t) powl(10, 9);
    std::vector<float> arr(N);

    time_call(num_repetitions, [&] () {
        fill_up_threaded(arr, num_threads);
    });


    time_call(num_repetitions, [&] () {
        resample_threaded(arr, num_threads);
    });

    return 0;
}
