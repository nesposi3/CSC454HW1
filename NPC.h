//
// Created by nick on 9/9/19.
//

#ifndef HOMEWORK1_NPC_H
#define HOMEWORK1_NPC_H

#include <iostream>
#include "Creature.h"
using namespace std;
class NPC : public Creature {

public:
    NPC(int type, int room);
};


#endif //HOMEWORK1_NPC_H
