//
// Created by nick on 9/9/19.
//

#ifndef HOMEWORK1_PC_H
#define HOMEWORK1_PC_H


#include "Creature.h"

class PC : public Creature {
    public:
        PC(int type,int room,int creatureNumber): Creature(type,room,creatureNumber){
            this->respect = 40;
        }
        void addRespect(int num);
        void subRespect(int num);
        int getRespect();
        virtual string toString();
        virtual bool isRoomSufficient(Room * room);
        virtual int reactToChange(bool clean);
    private:
        int respect;
};


#endif //HOMEWORK1_PC_H
