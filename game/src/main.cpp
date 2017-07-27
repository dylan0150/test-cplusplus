#include <string>
#include <SDL.h>
#include <stdio.h>

bool quit = false;

#include "sdlevent.cpp"

const int SCREEN_WIDTH              = 640;
const int SCREEN_HEIGHT             = 480;

const int KEY_PRESS_SURFACE_DEFAULT = 0;
const int KEY_PRESS_SURFACE_UP      = 1;
const int KEY_PRESS_SURFACE_DOWN    = 2;
const int KEY_PRESS_SURFACE_LEFT    = 3;
const int KEY_PRESS_SURFACE_RIGHT   = 4;
const int KEY_PRESS_SURFACE_TOTAL   = 5;

SDL_Window*  gWindow         = NULL;
SDL_Surface* gScreenSurface  = NULL;
SDL_Surface* gCurrentSurface = NULL;
SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];

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
      gScreenSurface = SDL_GetWindowSurface( gWindow );
    }
  }
  return success;
}

SDL_Surface* loadSurface( std::string path ) {
  SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
  if( loadedSurface == NULL ) {
    SDL_Log( "Unable to load image %d! SDL Error: %d", path.c_str(), SDL_GetError() );
  }
  return loadedSurface;
}

bool loadMedia() {
  bool success = true;
  gCurrentSurface = SDL_LoadBMP( "../res/test.bmp" );
  if ( gCurrentSurface == NULL ) {
    SDL_Log( "Unable to load image %d! SDL Error: %d", "../res/test.bmp", SDL_GetError() );
    success = false;
  }
  return success;
}

void close() {
  SDL_FreeSurface( gCurrentSurface );
  gCurrentSurface = NULL;
  SDL_DestroyWindow( gWindow );
  gWindow = NULL;
  SDL_Quit();
}

int main( int argc, char* args[] ) {
  if ( !init() )      { SDL_Log( "Failed to initialize!" ); close(); return 1; }
  if ( !loadMedia() ) { SDL_Log( "Failed to load media!" ); close(); return 1; }

  while ( !quit ) {
    pollEvents();
    SDL_BlitSurface( gCurrentSurface, NULL, gScreenSurface, NULL );
    SDL_UpdateWindowSurface( gWindow );
  }

  close();
  return 0;
}
