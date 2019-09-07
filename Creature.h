//
// Created by nick on 9/3/19.
//

#ifndef HOMEWORK1_CREATURE_H
#define HOMEWORK1_CREATURE_H


class Creature {
    public:
        Creature(int type, int room);
        int getType(){return this->creatureType;};
        int getRoom(){ return this->roomNumber;};
    private:
        int creatureType;
        int roomNumber;
};


#endif //HOMEWORK1_CREATURE_H
