#include <string>
#include <iostream>
#include "render.h"

void Render::Setup(std::string name, int w, int h) {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    
    
    window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, 0);
    rend = SDL_CreateRenderer(window, -1, 0);
    
    if(!rend) {
        std::cerr << "RENDER IS NULL" << std::endl;
    }
    IMG_Init(IMG_INIT_PNG);
    
    // int color = _color >> 16;
    
    SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
}   

SDL_Texture *Render::LoadSprite(std::string filename) {
    std::cout << "Loading " << filename << std::endl;

    SDL_Surface *tmp = IMG_Load(filename.c_str());
    if(tmp == nullptr) 
        std::cerr << "Failed loading " << filename << IMG_GetError() << std::endl;
    
    SDL_Texture * tex = SDL_CreateTextureFromSurface(rend, tmp);
    SDL_FreeSurface(tmp);
    return tex;
}

Render::~Render() {
    SDL_DestroyWindow(window);
}

void Render::DrawSprite(SDL_Texture* tex, int x, int y, int w, int h, int tX, int tY) {
    m_pos.x = x;
    m_pos.y = y;
    m_pos.w = w;
    m_pos.h = h;
    // std::cout << w << h << std::endl;
    
    // m_clip.x = tX;
    // m_clip.y = tY;
    // m_clip.w = w;
    // m_clip.h = h;
    
    SDL_RenderCopy(rend, tex, NULL, &m_pos);
}

void Render::getWH(SDL_Texture* tex, int &w, int &h) {
    SDL_QueryTexture(tex, NULL, NULL, &w, &h);
    // 
}

void Render::deleteTex(SDL_Texture* tex) {
    SDL_DestroyTexture(tex);
}

void Render::Update() {
    SDL_RenderPresent(rend);
    if(firstFrame) {
        firstFrame = false;
        previousTime = SDL_GetTicks();
    } else {
        previousTime = currentTime;
    }
    currentTime = SDL_GetTicks();
    // SDL_Delay(20); 
    // std::cout << (1000 / 60 - currentTime) + previousTime << std::endl;
    int delay = (1000 / 60 - currentTime) + previousTime;
    SDL_Delay(std::abs(delay));
}

void Render::Start() {
    SDL_RenderClear(rend);
}

void Render::MessageBox(std::string msg) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Hyper Scratch", msg.c_str(), window);
}

void Render::Scale(int x, int y) {
    SDL_RenderSetScale(rend, x, y);
}
void Render::UpdateTitle(std::string title) {
    SDL_SetWindowTitle(window, title.c_str());
}

void Render::DrawRect(SDL_Rect rect) {
    SDL_RenderFillRect(rend, &rect);
}

void Render::getMousePos(int &x, int &y) {
    SDL_GetMouseState(&x, &y);
}

void Render::update_win_size(int w, int h) {
    SDL_SetWindowSize(window, w, h);
}
