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
    int reactToChange(bool clean);
};


#endif //HOMEWORK1_ANIMAL_H
