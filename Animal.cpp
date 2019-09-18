//
// Created by nick on 9/9/19.
//

#include "Animal.h"
bool Animal::isRoomSufficient(Room *room) {
    return room->getState()<2;
}
string Animal::toString() {
    stringstream stream;
    string out;
    stream << "Animal " << creatureNumber;
    getline(stream,out);
    return out;
}
int Animal::reactToChange(int respect, int id,bool clean) {
    int diff = 1;
    string modifier = "";
    if(id==this->creatureNumber){
        diff = 3;
        modifier = " A lot";
    }
    if(clean){
        cout << this->toString() <<" licks your face" << modifier<< ". Respect is now " << respect + diff <<endl;
        return respect + diff;
    }else{
        cout <<this->toString() << " growls" << modifier<<". Respect is now " << respect - diff  <<endl;
        return respect - diff;
    }

}
int Animal::reactToDelete(int respect) {
    cout << this->toString() << " growls. Respect is now " << respect - 1 <<endl;
    return respect-1;
}