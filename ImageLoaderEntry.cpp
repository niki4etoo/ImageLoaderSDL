#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>
#include <string>
#include <vector>

#include "include/ImageLoaderManager.hpp"

using namespace std;

int main(int argc, char **argv)
{
  bool quit = false;
  SDL_Event event;

  SDL_Init(SDL_INIT_VIDEO);

  //Vector of image names
  vector<string> image_filenames{ "car_1" , "car_2" , "car_3" , "car_4" , "car_5" , "car_6" };
  unsigned int index = 3;
  ImageLoaderManager ilm(image_filenames, index);

  /**
  *** The main loop of the Image Loader
   **/
  while (!quit)
  {
      SDL_WaitEvent(&event);

      switch (event.type)
      {
          /* Look for a keypress */
          case SDL_KEYDOWN:
              /* Check the SDLKey values and move change the coords */
              switch( event.key.keysym.sym ){
                  case SDLK_LEFT:
                      //Update texture and move to the left of the vector
                      if(index - 1 == 0xffffffff) { //Vector beginning reached and unsigned int overflow
                        ilm.update_image(image_filenames, 0);
                        cout << "Beginning of the vector is reached! :)" << endl;
                        cout << "current index: " << index << endl;
                      } else if(index - 1 >= 0) {
                        ilm.update_image(image_filenames, --index);
                        cout << "current index: " << index << endl;
                        cout << "current index - 1: " << index - 1 << endl;
                      }
                      break;
                  case SDLK_RIGHT:
                      //Update texture and move to the right of the vector
                      if(index + 1 == image_filenames.size()){ // Vector end reached
                        ilm.update_image(image_filenames, image_filenames.size()-1);
                        cout << "End of the vector is reached! :)" << endl;
                        cout << "current index: " << index << endl;
                      } else if(index + 1 < image_filenames.size()) {
                        ilm.update_image(image_filenames, ++index);
                        cout << "current index: " << index << endl;
                      }
                      break;
                  default:
                      break;
              }
              break;
          case SDL_QUIT:
              quit = true;
              break;
      }

      //render update
      ilm.render_update();
  }

  //Free up the memory used for the Texture, Image surface, Renderer and Window
  ilm.free();

  SDL_Quit();

  return 0;
}
