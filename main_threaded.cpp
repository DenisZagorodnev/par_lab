#include <cstdlib>
#include <cstdio>
#include <math.h>
#include <ctime>
#include <thread>
#include <vector>
#include <iostream>
#include <limits>
#include <fstream>
#include "defs.h"


const int num_repetitions = 1;


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

//Проделать с массивом следующую операцию: `a[i]=a[i+1]+ a[i], a[N]=a[0]+ a[N]`.

void resample_threaded(std::vector<float> &arr, int num_threads) {
    std::vector<std::thread> threads;
    print_array(arr);
    long bunch_size = (arr.size() + num_threads - 1) / num_threads;
    float first = arr[0];
    for(long j = 0; j < num_threads; j++) {

        long from = bunch_size * j;
        long to = bunch_size * (j + 1);

        if (to > arr.size()) {
            to = arr.size();
        }

        float next = first;

        if (j < num_threads - 1) {
            next = arr[to];
        }

        threads.push_back(std::thread(resample_vector, std::ref(arr), from, to, next));
    }

    for (auto &th : threads) {
        th.join();
    }
    print_array(arr);

}


int main(int argc, const char *argv[]) {
    size_t N = (size_t) powl(10, 7);
    std::vector<float> arr(N);
    std::vector<int> num_threads{1, 2, 4, 8, 16};
    std::ofstream myfile;

    myfile.open ("threading_res.csv");
    myfile << "num_thread" << ',' <<  "fill_duration" << ',' << "resample_duration" << std::endl;
    for(auto const& num_thread: num_threads) {

        float fill_duration = time_call(num_repetitions, [&]() {
            fill_up_threaded(arr, num_thread);
        });


        float resample_duration = time_call(num_repetitions, [&]() {
            resample_threaded(arr, num_thread);
        });

        std::cout << num_thread << ',' <<  fill_duration << ',' << resample_duration << std::endl;
        myfile << num_thread << ',' <<  fill_duration << ',' << resample_duration << std::endl;
    }

    myfile.close();
    return 0;
}
