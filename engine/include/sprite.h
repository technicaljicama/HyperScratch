#include "texture.h"

#if 1
typedef struct {
    std::string name;
    int x;
    int y;
    int currentCostume;
    std::string fileName;
    int layer;
    int frameDelay;
} Sprite;
#else
class Sprite {
public:
    std::string name;
    int x;
    int y;
    int currentCostume;
    std::string fileName;
    int layer;
private:
    SDL_Texture* tex;
};
#endif
