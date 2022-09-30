#include <SDL.h>
#include <stdio.h>


SDL_Window* newWindow(const char* name, int startx, int starty, int w, int h, int visible)
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    SDL_Quit();
  }
  SDL_Window* window = SDL_CreateWindow(name, startx, starty,  w,  h, SDL_WINDOW_SHOWN);
  if (window == NULL) {
    SDL_Quit();
  }
  return window;
}


SDL_Surface* newSurface(SDL_Window* w, int rgb)
{
  char blue  = rgb & 0xff;
  rgb >>= 8;
  char green = rgb & 0xff;
  rgb >>= 8;
  char red = rgb & 0xff;
  SDL_Surface* surface = SDL_GetWindowSurface(w);
  SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, red, green, blue) );
  SDL_UpdateWindowSurface(w);
  return surface;
}


bool getEvent(SDL_Event* e)
{    
  while (SDL_PollEvent(e)) { };
  return (e->type != SDL_QUIT);
}

void cleanup(SDL_Window* w)
{
  SDL_DestroyWindow(w);
  SDL_Quit();
}

int main(int argc, char* args[])
{
  int startx = 800;
  int starty = 400;
  int width  = 500;
  int height = 200;
  int rgb = 0x880088;
  SDL_Window* window = newWindow("hello", startx, starty, width, height, -1);
  SDL_Surface* surface = newSurface(window, rgb);

  SDL_Event e;
  while (getEvent(&e)) {
    if (e.type == SDL_QUIT) {
      break;
    }
  }
  
  cleanup(window);

  return 0;
}
