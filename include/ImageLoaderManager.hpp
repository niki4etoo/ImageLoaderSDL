#ifndef __IMAGE_LOADER_MANAGER_H_
#define __IMAGE_LOADER_MANAGER_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <vector>
#include <string>

#include "Window.hpp"
#include "Renderer.hpp"
#include "Texture.hpp"

class ImageLoaderManager {
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Surface *image;
  SDL_Texture *texture;
public:
  ImageLoaderManager(std::vector<std::string> filenames, int index){
    //Title of the window and starting position (posX, posY)
    Window w("Image Loader with SDL2", 0, 0);
    window = w.getWindow();

    Renderer r(window);
    renderer = r.getRenderer();
    std::string image_path = "images/" + filenames.at(index) + ".png";
    image = IMG_Load(image_path.c_str());

    Texture t(renderer, image);
    texture = t.getTexture();
  }

  void update_image(std::vector<std::string> filenames, int index){
    std::string image_path = "images/" + filenames.at(index) + ".png";
    image = IMG_Load(image_path.c_str());

    Texture t(renderer, image);
    texture = t.getTexture();
  }

  SDL_Window * getWindow(){
    return window;
  }

  SDL_Renderer * getRenderer(){
    return renderer;
  }

  SDL_Surface * getImage(){
    return image;
  }

  SDL_Texture * getTexture(){
    return texture;
  }

  void render_update(){
    SDL_RenderCopy(getRenderer(), getTexture(), NULL, NULL);
    SDL_RenderPresent(getRenderer());
  }

  int free(){
    SDL_DestroyTexture(getTexture());
    SDL_FreeSurface(getImage());
    SDL_DestroyRenderer(getRenderer());
    SDL_DestroyWindow(getWindow());

    if(texture == NULL && image == NULL && renderer == NULL && window == NULL)
      return 0;
    else
      return 1;
  }

};

#endif // __IMAGE_LOADER_MANAGER_H_
