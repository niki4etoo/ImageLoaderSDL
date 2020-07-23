#ifndef __WINDOW_H_
#define __WINDOW_H_

#include <SDL2/SDL.h>
#include <string>

using namespace std;

class Window {
  SDL_Window *window;
  string title;
  unsigned short posX;
  unsigned short posY;
public:
  Window(string title, unsigned short posX, unsigned short posY) : title(""), posX(0), posY(0) {
    window = SDL_CreateWindow(title.c_str(),
        posX, posY, 640, 480, 0);
  }

  SDL_Window * getWindow(){
    return window;
  }
};

#endif // __WINDOW_H_
