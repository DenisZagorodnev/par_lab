#include <vector>
#include <iostream>
#include "defs.h"
#include <mpi.h>
#include <cstdlib>


const int num_repetitions = 10;
const int num_threads = 2;

int main(int argc, const char *argv[]) {

   const int num_threads = 2;
//   size_t N = (size_t) powl(10, 9);
//   int rank;
//   int root = 0;
//
//   rc= MPI_Init(&argc, &argv);
//
//   MPI_Comm_size(MPI_COMM_WORLD, &num_threads);
//   MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//   MPI_Barrier(MPI_COMM_WORLD);
//
//   long bunch_size = (arr.size() + num_threads - 1) / num_threads;
//   size_t N = (size_t) powl(10, 7);
//
//   std::vector<std::thread> threads;

//   long bunch_size = (arr.size() + num_threads - 1) / num_threads;

//   for (int i = 0; i < num_threads; i++) {
//        long from = bunch_size * i;
//        long to = bunch_size * (i + 1);
//        if (to > arr.size()) {
//            to = arr.size();
//        }
//        fill_up_vector(std::ref(arr), from, to);
//    }
//
//
//
//   MPI_Finalize()

    return 0;
}
