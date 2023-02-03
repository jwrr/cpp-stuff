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


