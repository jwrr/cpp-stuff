Conan
=====

This example uses the Conan Package Manager to install, compile and run a
trivial Boost test.

Install Conan
-------------

```
mkdir conan
cd conan
mkdir build
cd build
pip --version
pip install conan
```

Install Boost Using Conan
-------------------------

```
mkdir <this_folder>
cd <this_folder>
create conanfile.txt
mkdir build
cd build
conan install ..
## Build from source
# conan install .. --build=boost
# conan install .. --build=all
# conan install .. --build missing
conan info .. --graph=file.html
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake
cmake --build . --config Release
./conan1
```

Conan Videos
------------

Jfrog Academy provides [Free Conan Online Training](https://academy.jfrog.com/).

* ["Conan Package Manager for C++ in Practice" by Jerry Wiltse](https://www.youtube.com/watch?v=0ekPQvSCoXE)
* [Conan Package Manager for C++ in Practice](https://www.youtube.com/watch?v=X4bPsRAXHRs)
* [C++ Package Manager - A detailed introduction to Conan](https://www.youtube.com/watch?v=T6RZ5On3xz8)

