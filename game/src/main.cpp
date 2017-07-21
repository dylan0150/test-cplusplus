#include <string>
#include <SDL.h>
#include <stdio.h>


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

bool quit = false;
SDL_Event e;

bool init() {
  bool success = true;
  if ( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    success = false;
  } else {
    gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if ( gWindow == NULL ) {
      printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
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
    printf( "Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
  }
  return loadedSurface;
}

bool loadMedia() {
  bool success = true;
  gCurrentSurface = SDL_LoadBMP( "../res/test.bmp" );
  if ( gCurrentSurface == NULL ) {
    printf( "Unable to load image %s! SDL Error: %s\n", "../res/test.bmp", SDL_GetError() );
    success = false;
  }
  return success;
}

void pollEvents() {
  while ( SDL_PollEvent( &e ) != 0 ) {
    switch ( e.type ) {
      case SDL_QUIT: quit = true; break;
      case SDL_KEYDOWN:
        switch ( e.key.keysym.sym ) {
          case SDLK_UP    : printf("Key pressed %s\n", "SLK_UP" );     break;
          case SDLK_DOWN  : printf("Key pressed %s\n", "SDLK_DOWN" );  break;
          case SDLK_LEFT  : printf("Key pressed %s\n", "SDLK_LEFT" );  break;
          case SDLK_RIGHT : printf("Key pressed %s\n", "SDLK_RIGHT" ); break;
        } break;
    }
  }
}

void close() {
  SDL_FreeSurface( gCurrentSurface );
  gCurrentSurface = NULL;
  SDL_DestroyWindow( gWindow );
  gWindow = NULL;
  SDL_Quit();
}

int main( int argc, char* args[] ) {
  if ( !init() )      { printf( "Failed to initialize!\n" ); close(); return 1; }
  if ( !loadMedia() ) { printf( "Failed to load media!\n" ); close(); return 1; }

  while ( !quit ) {
    pollEvents();
    SDL_BlitSurface( gCurrentSurface, NULL, gScreenSurface, NULL );
    SDL_UpdateWindowSurface( gWindow );
  }

  close();
  return 0;
}
