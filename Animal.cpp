//
// Created by nick on 9/9/19.
//

#include "Animal.h"
bool Animal::isRoomSufficient(Room *room) {
    return room->getState()>0;
}
string Animal::toString() {
    stringstream stream;
    string out;
    stream << "Animal " << creatureNumber;
    getline(stream,out);
    return out;
}
int Animal::reactToChange(bool clean) {
    if(clean){
        cout << "Lick Face" << endl;
        return 1;
    }else{
        cout << "Growl" << endl;
        return -1;
    }

}