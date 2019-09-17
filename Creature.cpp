//
// Created by nick on 9/3/19.
//

#include "Creature.h"
Creature::Creature(int type, int room,int creatureNumber) {
    this->roomNumber = room;
    this->creatureType = type;
    this->creatureNumber = creatureNumber;
}
string Creature::toString() {
    stringstream stream;
    string out;
    stream << "Creature " << creatureNumber;
    getline(stream,out);
    return out;
}

bool Creature::isRoomSufficient(Room *room) {
    return true;
}

bool Creature::inSameRoom(Creature * other) {
    return(this->getRoom()==other->getRoom());
}
void Creature::setRoom(int num){
    this->roomNumber=num;
}
//Creature reactToChange should never happen
int Creature::reactToChange(bool clean) {
    return false;
}
