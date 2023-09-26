#include "project.h"


void looks_switchcostumeto(std::string name, Sprite &inst) {
    
    for(int i = 0; i < MAX_COSTUMES; i++) {
        if(costumes[i].name == name) {
            inst.currentCostume = i;
        }
    }
}
