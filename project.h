
#include "sprite.h"
#include "costume.h"

#include "blocks.h"

#define MAX_SPRITES 1
inline Sprite sprites[1] = {
	{"Sprite1", 94, 290, 0, "bfd67b7240c0a2658bb27af034a443e4.png", 1},
};
#define MAX_COSTUMES 2
inline Costume costumes[2] = {
	{"costume1", "ca504fe02c138b18b08a3848058b4103.png", 0 ,0 ,0},
	{"costume2", "bfd67b7240c0a2658bb27af034a443e4.png", 0 ,0 ,0},
};
inline void event_whenthisspriteclickedblock_0denise5(Sprite &_sprite) {
	looks_switchcostumeto("costume2", _sprite);
};
inline void event_whenflagclickedblock_3james1(Sprite &_sprite) {
	looks_switchcostumeto("costume2", _sprite);
};

inline void(*_spriteClicked[1])(Sprite &_sprite) {
	&event_whenthisspriteclickedblock_0denise5,
};

inline void(*_greenFlagClicked[1])(Sprite &_sprite) {
	&event_whenflagclickedblock_3james1,
};
