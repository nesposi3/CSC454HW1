//
// Created by nick on 9/3/19.
//

#ifndef HOMEWORK1_CREATURE_H
#define HOMEWORK1_CREATURE_H

#include <iostream>
#include <sstream>
#include "Room.h"

using namespace std;
class Creature {
    public:
        Creature(int type, int room,int creatureNumber);
        virtual int getType(){return this->creatureType;};
        virtual int getRoom(){ return this->roomNumber;};
        virtual string toString();
        virtual bool isRoomSufficient(Room * room);
        virtual int reactToChange(int respect, int id,bool clean);
        virtual int reactToDelete(int respect);
        int getCreatureNumber();
        bool inSameRoom( Creature* other);
        void setRoom(int num);
        void deleteFromSim();
    protected:
        int deleted;
        int creatureType;
        int roomNumber;
        int creatureNumber;
};


#endif //HOMEWORK1_CREATURE_H
