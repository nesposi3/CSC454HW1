//
// Created by nick on 9/3/19.
//

#include <sstream>
#include "Creature.h"
Creature::Creature(int type, int room) {
    this->roomNumber = room;
    this->creatureType = type;
}
string Creature::toString() {
    stringstream stream;
    string out;
    stream << "Creature " << creatureNumber;
    getline(stream,out);
    return out;
}