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
    int rc = MPI_Init(&argc, &argv);
    if (rc != MPI_SUCCESS) {
        std::cout << "so saaaad mpi failed" << std::endl;
        MPI_Abort(MPI_COMM_WORLD, rc);
    }

    int num_ranks = -1;
    MPI_Comm_size(MPI_COMM_WORLD, &num_ranks);

    int my_rank = -1;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    std::cout << my_rank << " out of " << num_ranks << std::endl;
    size_t N = (size_t) powl(10, 9);
    //size_t N = 6;
    long bunch_size = (N + num_ranks - 1) / num_ranks;
    int root = 0;

    float *arr = 0;
    if (my_rank == root) {
        arr = (float *)malloc(num_ranks*bunch_size*sizeof(float));
    }

    std::vector<float> bunch(bunch_size);
    fill_up_vector( std::ref(bunch), 0, bunch.size());

    MPI_Gather(&bunch[0], bunch_size, MPI_FLOAT, arr, bunch_size, MPI_FLOAT, root, MPI_COMM_WORLD);

    if(my_rank == root){
        for (size_t i = 0; i < N; i++) {
            std::cout << arr[i] << ", ";
        }
        std::cout << std::endl;
    }

// чтобы сделать resample_vector сегмента требуется получить(recive) первый элемент следующего(source) сегмента
// при этом свой первый передается(send) предыдущему(dest)
    float first = bunch[0];
    float next;
    int dest = my_rank - 1;
    if(dest < 0){
        dest = num_ranks - 1;
    }
    int source = my_rank + 1;
    if(source == num_ranks){
        source = 0;
    }
    MPI_Sendrecv(&first, 1, MPI_FLOAT, dest, 0,
                 &next,  1, MPI_FLOAT, source, 0,
                 MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    resample_vector(bunch, 0, bunch.size(), next);

    MPI_Gather(&bunch[0], bunch_size, MPI_FLOAT, arr, bunch_size, MPI_FLOAT, root, MPI_COMM_WORLD);

    if(my_rank == root){
        for (size_t i = 0; i < N; i++) {
            std::cout << arr[i] << ", ";
        }
        std::cout << std::endl;
    }


    MPI_Finalize();

    return 0;
}
