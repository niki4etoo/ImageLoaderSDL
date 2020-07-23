#ifndef __TEXTURE_H_
#define __TEXTURE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Texture {
  SDL_Texture *texture;
public:
  //Texture depends on SDL_Renderer and SDL_Surface
  Texture(SDL_Renderer *renderer, SDL_Surface *image){
    texture = SDL_CreateTextureFromSurface(renderer, image);
  }

  SDL_Texture * getTexture(){
    return texture;
  }
};

#endif // __TEXTURE_H_
