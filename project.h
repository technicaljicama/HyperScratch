
#include "sprite.h"
#include "costume.h"

#include "blocks.h"

#include "stage.h"

inline int gWhileLoop = -1;

#define MAX_SPRITES 2
inline Sprite sprites[2] = {
	{"Sprite1", 131, 175, 1, "bfd67b7240c0a2658bb27af034a443e4.png", 1},
	{"Abby", 145, 127, 8, "45de34b47a2ce22f6f5d28bb35a44ff5.png", 2},
};
#define MAX_COSTUMES 6
inline Costume costumes[6] = {
	{"costume1", "ca504fe02c138b18b08a3848058b4103.png", 0, 0 , 0, 47, 49},
	{"costume2", "bfd67b7240c0a2658bb27af034a443e4.png", 0, 0 , 0, 45, 52},
	{"abby-a", "809d9b47347a6af2860e7a3a35bce057.png", 1, 0 , 0, 31, 100},
	{"abby-b", "920f14335615fff9b8c55fccb8971984.png", 1, 0 , 0, 31, 100},
	{"abby-c", "34a175600dc009a521eb46fdbbbeeb67.png", 1, 0 , 0, 32, 100},
	{"abby-d", "45de34b47a2ce22f6f5d28bb35a44ff5.png", 1, 0 , 0, 32, 101},
};
#define MAX_STAGES 1
inline Stage stages[1] = {
	{"Bench With View", "962201a2b712a302fb087f8f0dcb2076.png"},
};
inline void event_whenflagclickedblock_0james8(Sprite &_sprite) {
	looks_switchcostumeto("costume1", _sprite);
	gWhileLoop++;
};
inline void control_foreverblock_3curtis10(Sprite &_sprite) {
	motion_goto("Abby", _sprite);
	looks_switchcostumeto("costume1", _sprite);
	motion_goto("Abby", _sprite);
};
inline void event_whenflagclickedblock_8robert1(Sprite &_sprite) {
	gWhileLoop++;
};
inline void control_foreverblock_9gerald0(Sprite &_sprite) {
	motion_goto("_random_", _sprite);
	motion_goto("_random_", _sprite);
};

#define MAX_WHILES 2
inline void(*_whileLoops[2])(Sprite &_sprite) {
	&control_foreverblock_3curtis10,
	&control_foreverblock_9gerald0,
};

inline void(*_spriteClicked[0])(Sprite &_sprite) {
};

inline void(*_greenFlagClicked[2])(Sprite &_sprite) {
	&event_whenflagclickedblock_0james8,
	&event_whenflagclickedblock_8robert1,
};
