SDL Examples
============

I don't know what I'm doing.


INSTALL FROM SOURCE
-------------------

```
git clone https://github.com/libsdl-org/SDL.git
cd SDL/
mkdir builds
cd builds/
cmake ..
make
sudo make install
```

INSTALL FROM APT
----------------

```
sudo rm -rf /usr/local/bin/sdl2-config /usr/local/include/SDL2 /usr/local/lib/libSDL2*
sudo apt install libsdl
```



 WHAT SDL VERSION IS INSTALLED
 -----------------------------

```
sdl2-config --version
2.25.0

or

dpkg -l | grep sdl
ii  libsdl2-2.0-0:amd64
```




