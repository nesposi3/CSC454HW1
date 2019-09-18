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
        cout <<this->toString() << " smiles" << modifier<< ". Respect is now " << respect + diff << endl;
        return respect + diff;
    }else{
        cout <<this->toString() << " grumbles" << modifier<< ". Respect is now " << respect - diff <<endl;
        return respect - diff;
    }
}
int NPC::reactToDelete(int respect) {
    cout << this->toString() << " grumbles. Respect is now " << respect-1 <<endl;
    return respect-1;
}