
#include "sprite.h"
#include "costume.h"

#include "blocks.h"

#include "stage.h"

inline int gWhileLoop = -1;

#define MAX_SPRITES 1
inline Sprite sprites[1] = {
	{"Abby", 219, -68, 6, "45de34b47a2ce22f6f5d28bb35a44ff5.png", 1, 0},
};
#define MAX_COSTUMES 4
inline Costume costumes[4] = {
	{"abby-a", "809d9b47347a6af2860e7a3a35bce057.png", 0, 0 , 0, 31, 100},
	{"abby-b", "920f14335615fff9b8c55fccb8971984.png", 0, 0 , 0, 31, 100},
	{"abby-c", "34a175600dc009a521eb46fdbbbeeb67.png", 0, 0 , 0, 32, 100},
	{"abby-d", "45de34b47a2ce22f6f5d28bb35a44ff5.png", 0, 0 , 0, 32, 101},
};
#define MAX_STAGES 2
inline Stage stages[2] = {
	{"Bench With View", "962201a2b712a302fb087f8f0dcb2076.png"},
	{"Blue Sky", "e7c147730f19d284bcd7b3f00af19bb6.png"},
};
inline void event_whenflagclickedblock_0catherine7(Sprite &_sprite) {
	gWhileLoop++;
};
inline void control_foreverblock_1john0(Sprite &_sprite) {

	if(sensing_mousedown()) {
	motion_goto("_random_", _sprite);
	looks_switchbackdropto("previous backdrop", _sprite);
	looks_switchbackdropto("next backdrop", _sprite);
	control_wait("0.5", _sprite);
	}
	
};

#define MAX_WHILES 1
inline void(*_whileLoops[1])(Sprite &_sprite) {
	&control_foreverblock_1john0,
};

inline void(*_spriteClicked[0])(Sprite &_sprite) {
};

inline void(*_greenFlagClicked[1])(Sprite &_sprite) {
	&event_whenflagclickedblock_0catherine7,
};
