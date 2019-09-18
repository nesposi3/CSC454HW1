#include "Room.h"
#include "Creature.h"
#include "NPC.h"
#include "Animal.h"
#include "PC.h"

Room *moveCreatue(string direction, Room **roomList, Room *currentRoom, Creature *movedCharacter) {
    currentRoom->removeCreature();
    if (direction == "east") {
        if (currentRoom->getEast() == -1) {
            cout << "No room to the East" << endl;
            return currentRoom;
        } else {
            if (roomList[currentRoom->getEast()]->getNumCreatures() == 10) {
                cout << "Room Full" << endl;
                return currentRoom;
            }
            cout << movedCharacter->toString() << " Moved toward the East" << endl;
            return roomList[currentRoom->getEast()];
        }
    } else if (direction == "west") {
        if (currentRoom->getWest() == -1) {
            cout << "No room to the West" << endl;
            return currentRoom;
        } else {
            if (roomList[currentRoom->getWest()]->getNumCreatures() == 10) {
                cout << "Room Full" << endl;
                return currentRoom;
            }
            cout << movedCharacter->toString() << " Moved toward the West" << endl;
            return roomList[currentRoom->getWest()];
        }
    } else if (direction == "south") {
        if (currentRoom->getSouth() == -1) {
            cout << "No room to the south" << endl;
            return currentRoom;
        } else {
            if (roomList[currentRoom->getSouth()]->getNumCreatures() == 10) {
                cout << "Room Full" << endl;
                return currentRoom;
            }
            cout << movedCharacter->toString() << " Moved toward the South" << endl;
            return roomList[currentRoom->getSouth()];
        }
    } else if (direction == "north") {
        if (currentRoom->getNorth() == -1) {
            cout << "No room to the North" << endl;
            return currentRoom;
        } else {
            if (roomList[currentRoom->getNorth()]->getNumCreatures() == 10) {
                cout << "Room Full" << endl;
                return currentRoom;
            }
            cout << movedCharacter->toString() << " Moved toward the North" << endl;
            return roomList[currentRoom->getNorth()];
        }
    } else {
        cout << "No known direction: " << direction << endl;
        return currentRoom;
    }
}

int main() {
    int numRooms, numCreatures;
    cin >> numRooms;
    if (numRooms < 1 || numRooms > 100) {
        return 1;
    }
    Room *roomList[numRooms];
    for (int i = 0; i < numRooms; ++i) {
        int state, north, south, east, west;
        cin >> state >> north >> south >> east >> west;
        roomList[i] = new Room(state, north, south, east, west, i);
    }
    cin >> numCreatures;
    Creature *creatures[numCreatures];
    PC *playerCharacter = NULL;
    Room *currentRoom = roomList[0];
    for (int i = 0; i < numCreatures; i++) {
        int type, room;
        cin >> type >> room;
        if (type == 0) {
            creatures[i] = new PC(type, room, i);
            playerCharacter = (PC *) creatures[i];
        } else if (type == 1) {
            creatures[i] = new Animal(type, room, i);

        } else if (type == 2) {
            creatures[i] = new NPC(type, room, i);

        } else {
            creatures[i] = new Creature(type, room, i);
        }
        roomList[room]->addCreature();
        if (type == 0) {
            currentRoom = roomList[room];
        }
    }
    while (true) {
        string command;
        getline(cin, command);
        if (!command.empty()) {
            if (command == "exit") {
                cout << "Goodbye" << endl;
                break;
            } else if (command == "look") {
                cout << currentRoom->toString() << endl;
                for (int i = 0; i < numCreatures; ++i) {
                    if (creatures[i]->inSameRoom(playerCharacter)) {
                        cout << creatures[i]->toString() << endl;
                    }
                }
            } else if (command == "clean") {
                if (!currentRoom->clean()) {
                    cout << "Cannot clean an already clean room" << endl;
                } else {
                    for (int i = 0; i < numCreatures; ++i) {
                        Creature *currentCreature = creatures[i];
                        if (currentCreature->inSameRoom(playerCharacter)) {
                            int respChange = currentCreature->reactToChange(playerCharacter->getRespect(),
                                                                            playerCharacter->getCreatureNumber(), true);
                            playerCharacter->setRespect(respChange);
                            if (!currentCreature->isRoomSufficient(currentRoom)) {
                                if (currentRoom->hasAvailableNeighbors(roomList)) {
                                    int newRoom = currentRoom->getRandomNeighbor();
                                    currentCreature->setRoom(newRoom);
                                    currentRoom->removeCreature();
                                    roomList[newRoom]->addCreature();
                                    if (!currentCreature->isRoomSufficient(roomList[newRoom])) {
                                        roomList[newRoom]->setState(1);
                                    }
                                    cout << currentCreature->toString() << " moves to the "
                                         << currentRoom->whichNeighbor(newRoom) << endl;
                                } else {
                                    currentCreature->deleteFromSim();
                                    currentRoom->removeCreature();
                                    for (int j = 0; j <numCreatures ; ++j) {
                                        if(creatures[j]->inSameRoom(playerCharacter)){
                                            int newResp = creatures[j]->reactToDelete(playerCharacter->getRespect());
                                            playerCharacter->setRespect(newResp);
                                        }
                                    }
                                }
                            }
                        }
                    }

                }

            } else if (command == "dirty") {
                if (!currentRoom->dirty()) {
                    cout << "Cannot dirty an already dirty room" << endl;
                } else {
                    for (int i = 0; i < numCreatures; ++i) {
                        Creature *currentCreature = creatures[i];
                        if (currentCreature->inSameRoom(playerCharacter)) {
                            int respChange = currentCreature->reactToChange(playerCharacter->getRespect(),
                                                                            playerCharacter->getCreatureNumber(),
                                                                            false);
                            playerCharacter->setRespect(respChange);
                            if (!currentCreature->isRoomSufficient(currentRoom)) {
                                if (currentRoom->hasAvailableNeighbors(roomList)) {
                                    int newRoom = currentRoom->getRandomNeighbor();
                                    currentCreature->setRoom(newRoom);
                                    currentRoom->removeCreature();
                                    roomList[newRoom]->addCreature();
                                    if (!currentCreature->isRoomSufficient(roomList[newRoom])) {
                                        roomList[newRoom]->setState(1);
                                    }
                                    cout << currentCreature->toString() << " moves to the "
                                         << currentRoom->whichNeighbor(newRoom) << endl;
                                } else {
                                    currentCreature->deleteFromSim();
                                    currentRoom->removeCreature();
                                    for (int j = 0; j <numCreatures ; ++j) {
                                        if(creatures[j]->inSameRoom(playerCharacter)){
                                            int newResp = creatures[j]->reactToDelete(playerCharacter->getRespect());
                                            playerCharacter->setRespect(newResp);
                                        }
                                    }
                                }
                            }
                        }
                    }

                }
            } else if (command == "north" || command == "south" || command == "east" || command == "west") {
                currentRoom = moveCreatue(command, roomList, currentRoom, playerCharacter);
                currentRoom->addCreature();
                playerCharacter->setRoom(currentRoom->getNum());
            } else if (command.find(':') != string::npos) {
                Creature *commandCreature;
                int name = stoi(command.substr(0, command.find(':')));
                string action = command.substr((1 + command.find(':')));
                commandCreature = creatures[name];
                if (commandCreature->inSameRoom(playerCharacter)) {
                    if (action == "look") {
                        cout << currentRoom->toString() << endl;
                    } else if (action == "clean") {
                        if (!currentRoom->clean()) {
                            cout << "Cannot clean an already clean room" << endl;
                        } else {
                            for (int i = 0; i < numCreatures; ++i) {
                                Creature *currentCreature = creatures[i];
                                if (currentCreature->inSameRoom(playerCharacter)) {
                                    int respChange = currentCreature->reactToChange(playerCharacter->getRespect(), name,
                                                                                    true);
                                    playerCharacter->setRespect(respChange);
                                    if (!currentCreature->isRoomSufficient(currentRoom)) {
                                        if (currentRoom->hasAvailableNeighbors(roomList)) {
                                            int newRoom = currentRoom->getRandomNeighbor();
                                            currentCreature->setRoom(newRoom);
                                            currentRoom->removeCreature();
                                            roomList[newRoom]->addCreature();
                                            if (!currentCreature->isRoomSufficient(roomList[newRoom])) {
                                                roomList[newRoom]->setState(1);
                                            }
                                            cout << currentCreature->toString() << " moves to the "
                                                 << currentRoom->whichNeighbor(newRoom) << endl;
                                        } else {
                                            currentCreature->deleteFromSim();
                                            currentRoom->removeCreature();
                                            for (int j = 0; j <numCreatures ; ++j) {
                                                if(creatures[j]->inSameRoom(playerCharacter)){
                                                    int newResp = creatures[j]->reactToDelete(playerCharacter->getRespect());
                                                    playerCharacter->setRespect(newResp);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if (action == "dirty") {
                        if (!currentRoom->dirty()) {
                            cout << "Cannot dirty an already dirty room" << endl;
                        } else {
                            for (int i = 0; i < numCreatures; ++i) {
                                Creature *currentCreature = creatures[i];
                                if (currentCreature->inSameRoom(playerCharacter)) {
                                    int respChange = currentCreature->reactToChange(playerCharacter->getRespect(), name,
                                                                                    false);
                                    playerCharacter->setRespect(respChange);
                                    if (!currentCreature->isRoomSufficient(currentRoom)) {
                                        if (currentRoom->hasAvailableNeighbors(roomList)) {
                                            int newRoom = currentRoom->getRandomNeighbor();
                                            currentCreature->setRoom(newRoom);
                                            currentRoom->removeCreature();
                                            roomList[newRoom]->addCreature();
                                            if (!currentCreature->isRoomSufficient(roomList[newRoom])) {
                                                roomList[newRoom]->setState(1);
                                            }
                                            cout << currentCreature->toString() << " moves to the "
                                                 << currentRoom->whichNeighbor(newRoom) << endl;
                                        } else {
                                            currentCreature->deleteFromSim();
                                            currentRoom->removeCreature();
                                            for (int j = 0; j <numCreatures ; ++j) {
                                                if(creatures[j]->inSameRoom(playerCharacter)){
                                                    int newResp = creatures[j]->reactToDelete(playerCharacter->getRespect());
                                                    playerCharacter->setRespect(newResp);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }

                    } else if (action == "north" || action == "south" || action == "west" || action == "east") {
                        Room *newRoom = moveCreatue(action, roomList, currentRoom, commandCreature);
                        newRoom->addCreature();
                        commandCreature->setRoom(newRoom->getNum());
                        if (!commandCreature->isRoomSufficient(newRoom)) {
                            newRoom->setState(1);
                        }
                    }
                } else {
                    cout << commandCreature->toString() << " is not in the same room as the PC" << endl;
                }
            } else if (command == "help") {
                string help = ("hey"
                               "there");
                cout << help << endl;
            } else {
                cout << "Unknown command: " << command << endl;
            }
            if (playerCharacter->getRespect() > 79) {
                cout << "Good ending" << endl;
                break;
            } else if (playerCharacter->getRespect() < 1) {
                cout << "Bad ending" << endl;
                break;
            }
        }

    }

    //cleanup
    for (int i = 0; i < numRooms; i++) {
        delete roomList[i];
    }
    for (int i = 0; i < numCreatures; i++) {
        delete creatures[i];
    }
    return 0;
}
