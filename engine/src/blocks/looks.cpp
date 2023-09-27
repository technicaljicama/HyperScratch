#include "project.h"


void looks_switchcostumeto(std::string name, Sprite &inst) {
    
    for(int i = 0; i < MAX_COSTUMES; i++) {
        if(costumes[i].name == name) {
            inst.currentCostume = i;
        }
    }
}

void looks_switchbackdropto(std::string name, Sprite &inst) {
    if(name == "next backdrop") {
        if(g_CurrentStage < (MAX_STAGES - 1)) {
            g_CurrentStage++;
        }
    }
    else if(name == "previous backdrop") {
        if(g_CurrentStage > (MAX_STAGES - 1)) {
            g_CurrentStage--;
        }
    }
    else {
        for(int i = 0; i < MAX_STAGES; i++) {
            if(stages[i].name == name) {
                g_CurrentStage = i;
            }
        }
    }
}
