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

Install, Compile and Run GoogleTEST using Conan
------------------------------------------

* The '-build=all' option builds from source files. Skip this option to download
  pre-built binaries.
* Root/sudo is **NOT** required. All packages are downloaded and built in your 
  home directory (~/.conan).
* If gtest is already installed on your system, then the conan install steps are 
  completely optional. Cmake will just use the gtest that you installed.
* Changing the Virtual Build Environment is optional. This is to show that Conan
  can download, install and use custom tools/versions.

```
## Download and Build packages
mkdir build_gtest
cd build_gtest

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
./epsilon_gtest
```

Use Conan to Install Boost Test
-------------------------------

```
## Download and Build packages
mkdir build_btest
cd build_btest

conan install .. --build=boost

## Optional - Change Virtual Build Environment
cmake --version
source conanbuild.sh
cmake --version
which cmake

## Compile Test using CMAKE
cp ../CMakeLists.txt.btest ../CMakeLists.txt
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake
cmake --build . --config Release

## Run Test
./epsilon_btest


```


