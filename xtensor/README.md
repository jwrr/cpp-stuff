xtensor
=======

Install xtensor from source
---------------------------

```
git clone https://github.com/xtensor-stack/xtl
git clone https://github.com/xtensor-stack/xtensor
git clone //github.com/xtensor-stack/xtensor-blas
sudo apt install libopenblas-dev
sudo apt install liblapack-dev

## For each of the projects:

cd <prj>
mkdir build
cd build
cmake ..
sudo make install
cd ../..
```

Compile and Run Examples
------------------------

```
g++ index.cpp
./a.out
```


