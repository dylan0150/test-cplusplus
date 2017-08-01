#include <string>
#include <SDL.h>
#include <stdio.h>

bool quit = false;

#include "sdlevent.cpp"

int SCREEN_WIDTH              = 640;
int SCREEN_HEIGHT             = 480;

SDL_Window* gWindow = NULL;

bool init() {
  bool success = true;
  if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    SDL_Log( "SDL could not initialize! SDL_Error: %d", SDL_GetError() );
    success = false;
  } else {
    gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if ( gWindow == NULL ) {
      SDL_Log( "Window could not be created! SDL_Error: %d", SDL_GetError() );
      success = false;
    } else {

    }
  }
  return success;
}

void close() {
  SDL_DestroyWindow( gWindow );
  gWindow = NULL;
  SDL_Quit();
}

int main( int argc, char* args[] ) {
  if ( !init() )      { SDL_Log( "Failed to initialize!" ); close(); return 1; }

  while ( !quit ) {
    pollEvents();
    SDL_UpdateWindowSurface( gWindow );
  }

  close();
  return 0;
}
