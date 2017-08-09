bool quit = false;
bool game_paused = false;

int SCREEN_WIDTH        = 640;
int SCREEN_HEIGHT       = 480;

SDL_Window*   gWindow   = NULL;

class gameTimer {
  unsigned long int lastTime = 0, currentTime;
  bool paused = false;
  unsigned int res = 0;
public:
  gameTimer() {}
  void start() {
    paused = false;
  }
  void pause() {
    paused = true;
  }
  void toggle() {
    paused = !paused;
  }
  void stop() {
    paused = true;
  }
  int update(int interval) {
    res = 0;
    currentTime = SDL_GetTicks();
    if ( currentTime < lastTime ) { lastTime = 0; };
    if ( currentTime > ( lastTime + interval ) ) {
      lastTime += interval;
      if ( !paused ) { res++; }
    }
    return res;
  }
};

gameTimer gametimer;

class threadPool {
  int max_threads = std::thread::hardware_concurrency();
  int active_threads = 0;
  std::vector<SDL_Thread*> pool;
public:
  threadPool() {
    SDL_Log( "THREADS %d", max_threads );
  }
  SDL_Thread* assign( void (*f)(void*) ) {
    if ( active_threads < max_threads ) {
      SDL_Thread* threadID = SDL_CreateThread( (f*), "thread", (void *)NULL );
      if ( threadID == NULL ) {
        SDL_Log("SDL_CreateThread failed: %d", SDL_GetError());
      } else {
        SDL_Log("SDL_CreateThread created: %d", threadID);
        pool.push_back( threadID );
        active_threads++;
      }
      return threadID;
    } else {
      SDL_Log("SDL_CreateThread max threads reached");
      return 0;
    }
  }
  bool clear( SDL_Thread* threadid ) {
    SDL_WaitThread(threadid, NULL);
    //TODO remove from thread pool / clear memory.
    return true;
  }
};

threadPool threadpool;
