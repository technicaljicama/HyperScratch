#include "main.h" 
#include "render.h"
// #include "project.h"

MainApp::MainApp() {
    renderer.Setup("Hyper Scratch", 480, 360);
    
    for(int i = 0; i < MAX_SPRITES; i++) {
        g_Textures[i] = renderer.LoadSprite(sprites[i].fileName);
        renderer.getWH(g_Textures[i], sprites[i].w, sprites[i].h);
    }
}

void MainApp::update() {
    int i = 0;
    while(!quit) {
        renderer.Start();
        
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if(mouse == false) { 
                        i = 1;
                        mouse = true;
                    } else {
                        i = 0;
                        mouse = false;
                    }
                    break;
                case SDL_MOUSEBUTTONUP:
                    mouse = false;
                    i = 0;
                    break;
            }
        }
        
        
        // for(int i = 0; i < MAX_SPRITES; i++) {
        renderer.DrawSprite(g_Textures[i], sprites[i].x, sprites[i].y, sprites[i].w, sprites[i].h, 0, 0);
        // }
        
        renderer.Update();
    }
}

MainApp::~MainApp() {
    for(int i = 0; i < MAX_SPRITES; i++) {
        renderer.deleteTex(g_Textures[i]);
    }
}
