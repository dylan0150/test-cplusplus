bool quit = false;

int SCREEN_WIDTH        = 640;
int SCREEN_HEIGHT       = 480;

SDL_Window*   gWindow   = NULL;

class PHYSX_Vector {
  int x, y;
public:
  PHYSX_Vector() {
    x = 0;
    y = 0;
  }
  PHYSX_Vector(int _x, int _y) {
    x = _x;
    y = _y;
  }
  void set(int _x, int _y) {
    x = _x;
    y = _y;
  }
  void add( PHYSX_Vector vector ) {
    x += vector.x;
    y += vector.y;
  }
};

class GameObject {
  PHYSX_Vector pos, vel, acl;
public:
  GameObject(int x, int y) {
    pos.set(x,y);
  }
  GameObject() {}
};

std::vector<GameObject> objects;
