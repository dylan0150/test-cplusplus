#include <string>
#include <vector>
#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <sstream>

#include "sdldefinitions.cpp"
#include "sdlobjects.cpp"
#include "sdlevent.cpp"
#include "sdltexture.cpp"

bool init() {
  if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    SDL_Log( "SDL could not initialize! SDL_Error: %d", SDL_GetError() );
    return false;
  }
  gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
  if ( gWindow == NULL ) {
    SDL_Log( "Window could not be created! SDL_Error: %d", SDL_GetError() );
    return false;
  }
  if ( !loadRender() ) {
    SDL_Log( "Render failed!" );
    return false;
  }
  return true;
}

void close() {
  SDL_DestroyTexture( gTexture );
  gTexture = NULL;
  SDL_DestroyRenderer( gRenderer );
  gRenderer = NULL;
  SDL_DestroyWindow( gWindow );
  gWindow = NULL;
  IMG_Quit();
  SDL_Quit();
}

void update() {
  SDL_Log( "Update %d", SDL_GetTicks() );
  updateObjects();
}

int main( int argc, char* args[] ) {
  if ( !init() ) { SDL_Log( "Failed to initialize!" ); close(); return 1; }
  while ( !quit ) {
    pollEvents();
    int updates = gametimer.update(1000);
    while ( updates > 0 ) {
      update();
    }
    renderToScreen();
  }
  close();
  return 0;
}
