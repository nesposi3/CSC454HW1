//
// Created by nick on 9/9/19.
//

#ifndef HOMEWORK1_PC_H
#define HOMEWORK1_PC_H


#include "Creature.h"

class PC : public Creature {
    public:
        PC(int type,int room): Creature(type,room){

        }
};


#endif //HOMEWORK1_PC_H
