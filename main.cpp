 #include "Room.h"
#include "Creature.h"
#include "NPC.h"
#include "Animal.h"
#include "PC.h"
Room * movePlayer(string direction, Room ** roomList, Room * currentRoom){
    currentRoom->removeCreature();
    if(direction=="east"){
        if(currentRoom->getEast() == -1){
            cout << "No room to the East" << endl;
            return currentRoom;
        }
        else{
            return roomList[currentRoom->getEast()];
        }
    } else
    if(direction=="west"){
        if(currentRoom->getWest() == -1){
            cout << "No room to the West" << endl;
            return currentRoom;
        }
        else{
            return roomList[currentRoom->getWest()];
        }
    } else
    if(direction=="south"){
        if(currentRoom->getSouth() == -1){
            cout << "No room to the south" << endl;
            return currentRoom;
        }
        else{
            return roomList[currentRoom->getSouth()];
        }
    } else
    if(direction=="north"){
        if(currentRoom->getNorth() == -1){
            cout << "No room to the North" << endl;
            return currentRoom;
        }
        else{
            return roomList[currentRoom->getNorth()];
        }
    }else{
        cout << "No known direction: " << direction << endl;
        return currentRoom;
    }
}


int main() {
    int numRooms, numCreatures;
    cin >> numRooms;
    if(numRooms <1 || numRooms > 100){
        return 1;
    }
    Room * roomList[numRooms];
    for (int i = 0; i <numRooms ; ++i) {
        int state, north, south, east, west;
        cin >> state >> north >> south >> east >> west;
        roomList[i] = new Room(state,north,south,east,west,i);
    }
    cin >>numCreatures;
    Creature * creatures[numCreatures];
    Room * currentRoom = roomList[0];
    Room * commandRoom = roomList[0];
    for(int i = 0; i<numCreatures; i++){
        int type,room;
        cin >> type >> room;
        if(type == 0){
            creatures[i] = new PC(type,room);
        }else if(type ==1){
            creatures[i] = new Animal(type,room);

        }else if (type == 2){
            creatures[i] = new NPC(type,room);

        }
        else{
            creatures[i] = new Creature(type,room);

        }
        roomList[room]->addCreature();
        if(type == 0){
            currentRoom =roomList[room];
        }
    }
    while (true) {
        string command;
        getline(cin, command);
        if(command != ""){
            if(command == "exit"){
                break;
            }else
            if(command == "look"){
                cout << currentRoom->toString() << endl;
            }else if(command == "clean"){
                currentRoom->clean();
            }else if(command =="dirty"){
                currentRoom->dirty();
            }
            else if(command == "north" || command =="south" || command =="east" || command == "west"){
                currentRoom = movePlayer(command,roomList,currentRoom);
                currentRoom->addCreature();
            } else if(command.find(':')!=string::npos){
                int name = stoi(command.substr(0,command.find(':')));
                string action = command.substr((1 + command.find(':')));
                if(action=="look"){
                    cout << roomList[creatures[name]->getRoom()]->toString() << endl;
                }
            }else{
                cout << "Unknown command: " << command  <<endl;
            }

        }

    }

    //cleanup
    delete(currentRoom);
    delete(commandRoom);
    for(int i =0; i<numRooms; i++){
        delete(roomList[i]);
    }
    for(int i = 0; i< numCreatures; i++){
        delete(creatures[i]);
    }
    return 0;
}
