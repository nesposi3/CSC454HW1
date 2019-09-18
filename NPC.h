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
    NPC(int type, int room,int numCreatures);
    virtual bool isRoomSufficient(Room * room);
    virtual int reactToChange(int respect, int id,bool clean) ;
    virtual string toString();
};


#endif //HOMEWORK1_NPC_H
