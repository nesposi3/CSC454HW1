//
// Created by nick on 9/9/19.
//

#include "NPC.h"

NPC::NPC(int type, int room,int creatureNumber) : Creature(type, room,creatureNumber) {

}
bool NPC::isRoomSufficient(Room *room) {
    return room->getState() > 0;
}
string NPC::toString() {
    stringstream stream;
    string out;
    stream << "NPC " << creatureNumber;
    getline(stream,out);
    return out;
}
int NPC::reactToChange(int respect, int id,bool clean) {
    int diff = 1;
    string modifier = "";
    if(id==this->creatureNumber){
        diff = 3;
        modifier = " A lot";
    }
    if(!clean){
        cout <<this->toString() << " licks your face" << modifier<< ". Respect is now " << respect + diff << endl;
        return respect + diff;
    }else{
        cout <<this->toString() << " growls" << modifier<< ". Respect is now " << respect - diff <<endl;
        return respect - diff;
    }
}