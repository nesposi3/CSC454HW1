//
// Created by nick on 9/9/19.
//

#ifndef HOMEWORK1_ANIMAL_H
#define HOMEWORK1_ANIMAL_H

#include <iostream>
#include "Creature.h"
using namespace std;
class Animal : public Creature{
    virtual string toString(){}

public:
    Animal(int type, int room) : Creature(type, room) {

    }
    virtual bool isRoomSufficient(Room * room);
};


#endif //HOMEWORK1_ANIMAL_H
