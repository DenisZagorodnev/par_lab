# Parallel labs

## Task


Сгенерировать линейный массив случайных чисел `a[]` типа float. 
Размер массива `N=10^9` чисел.  
Проделать с массивом следующую операцию: `a[i]=a[i+1]+ a[i], a[N]=a[0]+ a[N]`.


## Prerequisites

```shell
brew install libomp
brew install openmpi
```

## Build

```shell
mkdir cmake-build-release
cd cmake-build-release
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

## Run threaded

```shell
./cmake-build-release/app_threaded
```

## Run MPI

```shell
mpirun -np 2 ./cmake-build-release/app_mpi 
```
