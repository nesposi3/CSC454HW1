//
// Created by nick on 9/9/19.
//

#include "NPC.h"

NPC::NPC(int type, int room) : Creature(type, room) {

}
bool NPC::isRoomSufficient(Room *room) {
    return room->getState() > 0;
}
