//
// Created by nick on 9/9/19.
//

#include "NPC.h"

NPC::NPC(int type, int room,int creatureNumber) : Creature(type, room,creatureNumber) {

}
bool NPC::isRoomSufficient(Room *room) {
    return room->getState() < 2;
}
string NPC::toString() {
    stringstream stream;
    string out;
    stream << "NPC " << creatureNumber;
    getline(stream,out);
    return out;
}
int NPC::reactToChange(bool clean) {
    if(clean){
        cout << "Grumble" <<endl;
        return -1;
    }else{
        cout << "Smile" <<endl;
        return 1;
    }
}