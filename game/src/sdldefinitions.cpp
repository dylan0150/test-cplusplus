bool quit = false;

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
    lastTime = 0;
  }
  int update(int interval ) {
    res = 0;
    if ( currentTime < lastTime ) { lastTime = 0; };
    if ( currentTime > lastTime + interval ) {
      lastTime += interval;
      res++;
    }
    return res;
  }
};

gameTimer gametimer;
