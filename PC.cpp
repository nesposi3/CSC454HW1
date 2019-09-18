//
// Created by nick on 9/9/19.
//

#include "PC.h"

void PC::addRespect(int num) {
    this->respect = this->respect + num;
}

void PC::subRespect(int num) {
    this->respect = this->respect - num;
}
bool PC::isRoomSufficient(Room *room) {
    return true;
}
string PC::toString() {
    stringstream stream;
    string out;
    stream << "PC " << creatureNumber;
    getline(stream,out);
    return out;
}
int PC::getRespect() {
    return this->respect;
}
// PC will not change its respect
int PC::reactToChange(int respect, int id,bool clean) {
    return respect;
}

void PC::setRespect(int num) {
    this->respect = num;
}
