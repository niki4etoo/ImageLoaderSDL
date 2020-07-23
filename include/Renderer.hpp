#ifndef __RENDERER_H_
#define __RENDERER_H_

#include <SDL2/SDL.h>

class Renderer {
  SDL_Renderer * renderer;
public:
  //Renderer depends on SDL_Window
  Renderer(SDL_Window * window){
    renderer = SDL_CreateRenderer(window, -1, 0);
  }

  SDL_Renderer * getRenderer(){
    return renderer;
  }

};

#endif // __RENDERER_H_
