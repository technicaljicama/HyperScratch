
#include "sprite.h"
#include "costume.h"

#include "blocks.h"

#include "stage.h"

inline int gWhileLoop = -1;

#define MAX_SPRITES 2
inline Sprite sprites[2] = {
	{"Sprite1", 58, 149, 1, "bfd67b7240c0a2658bb27af034a443e4.png", 1},
	{"Abby", 72, 101, 8, "45de34b47a2ce22f6f5d28bb35a44ff5.png", 2},
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
#define MAX_STAGES 2
inline Stage stages[2] = {
	{"Bench With View", "962201a2b712a302fb087f8f0dcb2076.png"},
	{"Blue Sky", "e7c147730f19d284bcd7b3f00af19bb6.png"},
};
inline void event_whenflagclickedblock_0kenneth0(Sprite &_sprite) {
	looks_switchcostumeto("costume1", _sprite);
	gWhileLoop++;
};
inline void control_foreverblock_3rosa6(Sprite &_sprite) {
	motion_goto("Abby", _sprite);
	looks_switchcostumeto("costume1", _sprite);
	motion_goto("Abby", _sprite);
};
inline void event_whenflagclickedblock_8chasity8(Sprite &_sprite) {
	gWhileLoop++;
};
inline void control_foreverblock_9mary3(Sprite &_sprite) {
	control_if(aaaaaaaaa, _sprite);
	motion_goto("_random_", _sprite);
	looks_switchbackdropto("next backdrop", _sprite);
	looks_switchbackdropto("next backdrop", _sprite);

	if(sensing_mousedown()) {
	sensing_mousedown(_sprite);
};

#define MAX_WHILES 2
inline void(*_whileLoops[2])(Sprite &_sprite) {
	&control_foreverblock_3rosa6,
	&control_foreverblock_9mary3,
};

inline void(*_spriteClicked[0])(Sprite &_sprite) {
};

inline void(*_greenFlagClicked[2])(Sprite &_sprite) {
	&event_whenflagclickedblock_0kenneth0,
	&event_whenflagclickedblock_8chasity8,
};
