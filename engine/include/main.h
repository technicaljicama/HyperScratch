#include "render.h"

class MainApp {
public:
    MainApp();
    ~MainApp();
    
    void update();
private:
    bool quit = false;
    bool mouse;
    Render renderer;
    SDL_Event event;
};
