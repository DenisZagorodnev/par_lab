cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 11)
project(par)

## Custom threaded version
add_executable(app_threaded
        main_threaded.cpp
        timing.cpp
        core.cpp)


## OMP version
add_executable(app_omp
        main_omp.cpp
        timing.cpp
        core.cpp)

find_package(OpenMP REQUIRED)
if(OpenMP_CXX_FOUND)
    target_link_libraries(app_omp PUBLIC OpenMP::OpenMP_CXX)
endif()


## MPI version
add_executable(app_mpi
        main_mpi.cpp
        timing.cpp
        core.cpp)

find_package(MPI REQUIRED)

include_directories(${MPI_INCLUDE_PATH})

target_link_libraries(app_mpi ${MPI_LIBRARIES})

if(MPI_COMPILE_FLAGS)
    set_target_properties(app_mpi PROPERTIES COMPILE_FLAGS "${MPI_COMPILE_FLAGS}")
endif()

if(MPI_LINK_FLAGS)
    set_target_properties(app_mpi PROPERTIES LINK_FLAGS "${MPI_LINK_FLAGS}")
endif()
