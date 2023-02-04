epsilon
=======

Description
-----------
* Measure smallest value that makes a difference for float, double and long double.
* Reference: https://www.youtube.com/playlist?list=PLzn6LN6WhlN1Lic9M9mbzqV3ASokOdnFM
* Course: Programming Techniques for Scientific Simulation 1
* Lecturer: Matthias Troyer

Install GoogleTest on Ubuntu 20.04
----------------------------------

```
sudo apt update
sudo apt upgrade
sudo apt install libgtest-dev
cd /usr/src/gtest
sudo mkdir build
cd build
sudo cmake ..
sudo make
sudo cp ./lib/libgtest*.a /usr/local/lib
```

Install, Compile and Run GTEST using Conan
------------------------------------------

## Download and Build packages
mkdir build_conan
cd build_conan

## The '-build=all' option builds from source files. Skip this option to
## download pre-built binaries. All packages are downloaded and built in
## your home directory (~/.conan).
## Root/sudo is **NOT** required. The conan install step is completely optional
## if you already have gtest installed on your system.

conan install .. -build=all

## Optional - Change Virtual Build Environment
cmake --version
source conanbuild.sh
cmake --version
which cmake

## Compile Test using CMAKE
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake
cmake --build . --config Release

## Run Test
./epsilon_test


