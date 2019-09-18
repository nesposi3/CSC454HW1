//
// Created by nick on 9/3/19.
//

#include "Creature.h"
Creature::Creature(int type, int room,int creatureNumber) {
    this->roomNumber = room;
    this->creatureType = type;
    this->creatureNumber = creatureNumber;
    this->deleted = 0;
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
    return(this->getRoom()==other->getRoom() && (this->deleted==0 && other->deleted==0));
}
void Creature::setRoom(int num){
    this->roomNumber=num;
}
//Creature reactToChange should never happen
int Creature::reactToChange(int respect, int id, bool clean) {
    return respect;
}

int Creature::getCreatureNumber() {
    return this->creatureNumber;
}

void Creature::deleteFromSim() {
    this->deleted = 1;
    cout << this->toString() << " had nowhere to go, so it burrowed through the ceiling" << endl;
}

int Creature::reactToDelete(int respect) {
    return respect;
}
