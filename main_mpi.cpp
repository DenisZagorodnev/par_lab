#include <vector>
#include <iostream>
#include "defs.h"
#include <mpi.h>
#include <cstdlib>
#include <math.h>
#include <unistd.h>

const int num_repetitions = 10;
const int num_threads = 2;

int main(int argc, char *argv[]) {

    int num_ranks = 2;
    size_t N = (size_t) powl(10, 9);
    int rank;
    int root = 0;

    int rc = MPI_Init(&argc, &argv);
    if (rc != MPI_SUCCESS) {
        std::cout << "so saaaad mpi failed" << std::endl;
        MPI_Abort(MPI_COMM_WORLD, rc);
    }


    MPI_Comm_size(MPI_COMM_WORLD, &num_ranks);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    std::cout << rank << " out of " << num_ranks << std::endl;
//   MPI_Barrier(MPI_COMM_WORLD);


    MPI_Finalize();

    return 0;
}
