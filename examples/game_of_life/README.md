Game of Life
============

Description
-----------


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
mkdir build
cd build

conan install .. --build=gtest

## Optional - Change Virtual Build Environment
cmake --version
source conanbuild.sh
cmake --version
which cmake

## Compile Test using CMAKE
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake
cmake --build . --config Release

## Run Test
./gol_gtest
```


