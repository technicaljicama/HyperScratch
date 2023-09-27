#include "project.h"

void control_wait(std::string duration, Sprite &inst) {
    int time = (std::stof(duration) * 60);
    inst.frameDelay = time;
}
