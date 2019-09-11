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

int PC::getRespect() {
    return this->respect;
}
