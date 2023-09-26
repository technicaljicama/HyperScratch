#include "main.h" 
#include "render.h"

#include <ctime>
// #include "project.h"

MainApp::MainApp() {
    std::srand(time(NULL));
    renderer.Setup("Hyper Scratch", 480, 360);
    
    for(int i = 0; i < MAX_COSTUMES; i++) {
        g_Textures[i] = renderer.LoadSprite(costumes[i].fileName);
        renderer.getWH(g_Textures[i], costumes[i].w, costumes[i].h);
    }
    _greenFlagClicked[0](sprites[0]);
}

void MainApp::update() {
    // int i = 0;
    
    while(!quit) {
        renderer.Start();
        renderer.getMousePos(mX, mY);
        
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if(mouse == false) { 
                        // i = 1;
                        mouse = true;
                    } else {
                        // i = 0;
                        mouse = false;
                    }
                    break;
                case SDL_MOUSEBUTTONUP:
                    mouse = false;
                    // i = 0;
                    break;
            }
        }
        if(gWhileLoop != -1) {
            _whileLoops[gWhileLoop](sprites[0]);
        }
        // std::cout << sprites[0].currentCostume << std::endl;
        
        // for(int i = 0; i < MAX_SPRITES; i++) {
        renderer.DrawSprite(g_Textures[sprites[0].currentCostume], sprites[0].x, sprites[0].y, costumes[sprites[0].currentCostume].w, costumes[sprites[0].currentCostume].h, 0, 0);
        // }
        
        renderer.Update();
    }
}

MainApp::~MainApp() {
    for(int i = 0; i < MAX_SPRITES; i++) {
        renderer.deleteTex(g_Textures[i]);
    }
}
