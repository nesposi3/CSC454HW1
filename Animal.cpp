//
// Created by nick on 9/9/19.
//

#include "Animal.h"
bool Animal::isRoomSufficient(Room *room) {
    return room->getState()<2;
}