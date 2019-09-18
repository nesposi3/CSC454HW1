//
// Created by nick on 9/9/19.
//

#ifndef HOMEWORK1_ANIMAL_H
#define HOMEWORK1_ANIMAL_H

#include <iostream>
#include "Creature.h"
using namespace std;
class Animal : public Creature{

public:
    Animal(int type, int room,int creatureNumber) : Creature(type, room,creatureNumber) {

    }
    virtual string toString();
    virtual bool isRoomSufficient(Room * room);
    virtual int reactToChange(int respect, int id,bool clean);
    virtual int reactToDelete(int repsect);
};


#endif //HOMEWORK1_ANIMAL_H
