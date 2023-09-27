#include "main.h" 
#include "render.h"

#include <ctime>
#include <iostream>
// #include "project.h"


MainApp::MainApp() {
    std::srand(time(NULL));
    renderer.Setup("Hyper Scratch", 480, 360);
    
    for(int i = 0; i < MAX_COSTUMES; i++) {
        g_Textures[i] = renderer.LoadSprite(costumes[i].fileName);
        renderer.getWH(g_Textures[i], costumes[i].w, costumes[i].h);
    }
    
    for(int i = 0; i < MAX_STAGES; i++) {
        g_StageTextures[i] = renderer.LoadSprite(stages[i].fileName);
        renderer.getWH(g_Textures[i], costumes[i].w, costumes[i].h);
    }
    
    for(int i = 0; i < MAX_SPRITES; i++) {
       _greenFlagClicked[i](sprites[i]); //WARNING: THIS IS NEEDS TO BE CHANGED
       // std::cout << i << std::endl;
    }
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
            for(int i = 0; i < gWhileLoop+1; i++) {
                _whileLoops[i](sprites[i]); //WARNING: THIS IS NEEDS TO BE CHANGED
                // std::cout << gWhileLoop << std::endl;
            }
        }
        
        renderer.DrawSprite(g_StageTextures[0], 0, 0, 480, 360, 0, 0);
        // std::cout << sprites[0].currentCostume << std::endl;
        
        for(int i = 0; i < MAX_SPRITES; i++) {
            // std::cout << i << std::endl;
            renderer.DrawSprite(g_Textures[sprites[i].currentCostume], sprites[i].x, sprites[i].y, costumes[sprites[i].currentCostume].w, costumes[sprites[i].currentCostume].h, 0, 0);
        }
        
        renderer.Update();
    }
}

MainApp::~MainApp() {
    for(int i = 0; i < MAX_SPRITES; i++) {
        renderer.deleteTex(g_Textures[i]);
    }
}
