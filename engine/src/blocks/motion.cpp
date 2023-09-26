#include "project.h"
#include <iostream>

void motion_goto(std::string type, Sprite &inst) {
    if(type == "_random_") {
        inst.x = (int)std::rand() % 480;
        inst.y = (int)std::rand() % 360;
        // std::cout << inst.x << std::endl;
    } else if(type == "_mouse_") {
        inst.x = mX;
        inst.y = mY;
    }
}
