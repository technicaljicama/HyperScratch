
#include "sprite.h"
#include "costume.h"

#include "blocks.h"

inline int gWhileLoop = -1;

#define MAX_SPRITES 2
inline Sprite sprites[2] = {
	{"Sprite1", 85, 106, 1, "bfd67b7240c0a2658bb27af034a443e4.png", 2},
	{"Abby", 216, -96, 5, "45de34b47a2ce22f6f5d28bb35a44ff5.png", 1},
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
inline void event_whenthisspriteclickedblock_0gregory8(Sprite &_sprite) {
	looks_switchcostumeto("costume2", _sprite);
};
inline void event_whenflagclickedblock_3micah0(Sprite &_sprite) {
	looks_switchcostumeto("costume1", _sprite);
	motion_goto("_mouse_", _sprite);
	gWhileLoop++;
};
inline void control_foreverblock_8sara0(Sprite &_sprite) {
	motion_goto("Abby", _sprite);
	looks_switchcostumeto("costume1", _sprite);
	looks_switchcostumeto("costume1", _sprite);
	motion_goto("Abby", _sprite);
	motion_goto("_random_", _sprite);
};
inline void event_whenflagclickedblock_17patricia7(Sprite &_sprite) {
	gWhileLoop++;
};
inline void control_foreverblock_18roy4(Sprite &_sprite) {
	motion_goto("_random_", _sprite);
};

#define MAX_WHILES 2
inline void(*_whileLoops[2])(Sprite &_sprite) {
	&control_foreverblock_8sara0,
	&control_foreverblock_18roy4,
};

inline void(*_spriteClicked[1])(Sprite &_sprite) {
	&event_whenthisspriteclickedblock_0gregory8,
};

inline void(*_greenFlagClicked[2])(Sprite &_sprite) {
	&event_whenflagclickedblock_3micah0,
	&event_whenflagclickedblock_17patricia7,
};
