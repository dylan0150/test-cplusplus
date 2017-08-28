SDL_Texture*  gTexture  = NULL;
SDL_Renderer* gRenderer = NULL;

SDL_Texture* loadTexture( std::string path ) {
  SDL_Texture* newTexture = NULL;
  SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
  if ( loadedSurface == NULL ) {
    SDL_Log( "Unable to load image %d! SDL_image Error: %d", path.c_str(), IMG_GetError() );
  } else {
    newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
    if ( newTexture == NULL ) {
      SDL_Log( "Unable to load texture from image %d! SDL Error: %d", path.c_str(), SDL_GetError() );
    }
    SDL_FreeSurface( loadedSurface );
  }
  return newTexture;
}

bool loadMedia() {
  gTexture = loadTexture( "../res/test.png" );
  if ( gTexture == NULL ) {
    SDL_Log( "Failed to load texture image!" );
    return false;
  }
  return true;
}

bool loadRender() {
  gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
  if( gRenderer == NULL ) {
    SDL_Log( "Renderer could not be created! SDL Error: %d", SDL_GetError() );
    return false;
  }
  SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
  int imgFlags = IMG_INIT_PNG;
  if ( !( IMG_Init( imgFlags ) & imgFlags ) ) {
    SDL_Log( "SDL_image could not initialize! SDL_image Error: %d", IMG_GetError() );
    return false;
  }
  if ( !loadMedia() ) { return false; }
  return true;
}

void renderToScreen() {
  SDL_RenderClear( gRenderer );
  SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
  SDL_RenderPresent( gRenderer );
}
