# Parallel labs

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

## Run

```shell
./app_threaded
```
