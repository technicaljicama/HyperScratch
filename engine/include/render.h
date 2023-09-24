#ifndef RENDER_H
#define RENDER_H


#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "project.h"

class Render {
public:
    SDL_Texture* LoadSprite(std::string filename);
    void DrawSprite(SDL_Texture* tex, int x, int y, int w, int h, int tX, int tY);
    void Setup(std::string name, int w, int h);
    void Update();
    void Start();
    void MessageBox(std::string msg);
    void Scale(int x, int y);
    void UpdateTitle(std::string title);
    void DrawRect(SDL_Rect rect);
    void update_win_size(int w, int h);
    void deleteTex(SDL_Texture* tex);
    void getWH(SDL_Texture* tex, int &w, int &h);
    ~Render();
private:
    SDL_Window *window;
    SDL_Renderer *rend;
    SDL_Rect m_clip;
    SDL_Rect m_pos;
};

inline SDL_Texture* g_Textures[MAX_SPRITES];

// inline Render renderer;

#endif
