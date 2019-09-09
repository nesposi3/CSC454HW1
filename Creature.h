//
// Created by nick on 9/3/19.
//

#ifndef HOMEWORK1_CREATURE_H
#define HOMEWORK1_CREATURE_H

#include <iostream>
using namespace std;
class Creature {
    public:
        Creature(int type, int room);
        virtual int getType(){return this->creatureType;};
        virtual int getRoom(){ return this->roomNumber;};
        virtual string toString();

    protected:
        int creatureType;
        int roomNumber;
        int creatureNumber;
};


#endif //HOMEWORK1_CREATURE_H
