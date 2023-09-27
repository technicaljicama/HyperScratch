
#include "sprite.h"
#include "costume.h"

#include "blocks.h"

inline int gWhileLoop = -1;

#define MAX_SPRITES 3
inline Sprite sprites[3] = {
	{"Instructions", 66, 340, 0, "a5f4cfd0c0da2cf088f4bbeb8bc28b5d.png", 3},
	{"Ella", 176, 49, 1, "18b662ddbb52c2d69ecbbaa965bb8efe.png", 2},
	{"Chica", 6, 41, 2, "af49656a26242c304fdca0c03488ab6e.png", 1},
};
#define MAX_COSTUMES 3
inline Costume costumes[3] = {
	{"instructions", "a5f4cfd0c0da2cf088f4bbeb8bc28b5d.png", 0, 0 , 0, 426, -50},
	{"cassy-chillin", "18b662ddbb52c2d69ecbbaa965bb8efe.png", 1, 0 , 0, 86, 200},
	{"girl2-standing", "af49656a26242c304fdca0c03488ab6e.png", 2, 0 , 0, 86, 180},
};
