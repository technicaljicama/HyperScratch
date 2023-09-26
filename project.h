
#include "sprite.h"
#include "costume.h"

#include "blocks.h"

inline int gWhileLoop = -1;

#define MAX_SPRITES 1
inline Sprite sprites[1] = {
	{"Sprite1", 0, -52, 0, "bfd67b7240c0a2658bb27af034a443e4.png", 1},
};
#define MAX_COSTUMES 2
inline Costume costumes[2] = {
	{"costume1", "ca504fe02c138b18b08a3848058b4103.png", 0 ,0 ,0},
	{"costume2", "bfd67b7240c0a2658bb27af034a443e4.png", 0 ,0 ,0},
};
inline void event_whenthisspriteclickedblock_0ruth5(Sprite &_sprite) {
	looks_switchcostumeto("costume2", _sprite);
};
inline void event_whenflagclickedblock_3john8(Sprite &_sprite) {
	looks_switchcostumeto("costume1", _sprite);
	motion_goto("_mouse_", _sprite);
	gWhileLoop++;
};
inline void control_foreverblock_8josefina6(Sprite &_sprite) {
	motion_goto("_mouse_", _sprite);
};

#define MAX_WHILES 1
inline void(*_whileLoops[1])(Sprite &_sprite) {
	&control_foreverblock_8josefina6,
};

inline void(*_spriteClicked[1])(Sprite &_sprite) {
	&event_whenthisspriteclickedblock_0ruth5,
};

inline void(*_greenFlagClicked[1])(Sprite &_sprite) {
	&event_whenflagclickedblock_3john8,
};
