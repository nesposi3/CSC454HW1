//
// Created by nick on 9/1/19.
//

#include "Room.h"
Room::Room(int state, int north, int south, int east, int west, int num) {
    this->state = state;
    this->north = north;
    this->south = south;
    this->east = east;
    this->west = west;
    this->num = num;
    this->numCreatures = 0;
}
int Room::getNum() {
    return this->num;
}
int Room::getState() {
    return  this->state;
}

int Room::getNorth() {
    return this->north;
}

int Room::getSouth() {
    return this->south;
}

int Room::getEast() {
    return this->east;
}

int Room::getWest() {
    return this->west;
}
void Room::addCreature(){
    this->numCreatures++;
}
void Room::removeCreature() {
    this->numCreatures--;
}
int Room::getNumCreatures(){
    return this->numCreatures;
}

bool Room::clean() {
    if(this->state!=0){
        this->state--;
        return true;
    }else{
        return false;
    }
}
bool Room::dirty() {
    if(this->state!=2){
        this->state++;
        return true;
    }else{
        return false;
    }
}

string Room::toString() {
    stringstream stream;
    string out;
    string cleanStatus;
    if(this->state==2){
        cleanStatus = "dirty";
    }
    else if(this->state==1){
        cleanStatus = "half dirty";
    }
    else{
        cleanStatus="clean";
    }

    stream << "Room no. " <<this->num  <<". "<< this->numCreatures << " creatures. " << "Cleanliness: " << cleanStatus ;
    if(this->hasNeighbors()){
        stream << ". Neighbors to the";
    }
    if(this->north!=-1){
        stream << " north";
    }
    if(this->south!=-1){
        stream << " south";
    }
    if(this->east!=-1){
        stream << " east";
    }
    if(this->west!=-1){
        stream << " west";
    }
    stream << ". Creatures:";
    getline(stream,out);
    return out;
}

bool Room::hasNeighbors() {
    return (this->east!=-1 || this->south !=-1 || this->north !=-1 || this->west !=-1);
}

bool Room::hasAvailableNeighbors(Room ** roomList){
    bool out = false;
    if(!this->hasNeighbors()){
        return false;
    }
    if(this->east!=-1){
        out = !roomList[this->east]->isFull() || out;
    }
    if(this->west!=-1){
        out = !roomList[this->west]->isFull() || out;
    }
    if(this->north!=-1){
        out = !roomList[this->north]->isFull() || out;
    }
    if(this->south!=-1){
        out = !roomList[this->south]->isFull() || out;
    }
    return out;
}

vector<int> Room::getNeighbors() {
    vector<int> out = vector<int>();
    if(this->north!=-1){
        out.push_back(this->north);
    }
    if(this->south!=-1){
        out.push_back(this->south);
    }
    if(this->east!=-1){
        out.push_back(this->east);
    }
    if(this->west!=-1){
        out.push_back(this->west);
    }
    return out;
}

int Room::getRandomNeighbor() {
    vector<int> neighbors = this->getNeighbors();
    int randNum = (rand() % neighbors.size());
    return neighbors[randNum];
}

bool Room::isFull() {
    return (this->getNumCreatures()>9);
}

void Room::setState(int num) {
    this->state = num;
}

string Room::whichNeighbor(int newRoomNumber) {
    if(this->east==newRoomNumber){
        return "East";
    }else
    if(this->west==newRoomNumber){
        return "West";
    }else
    if(this->south==newRoomNumber){
        return "South";
    }else if(this->north==newRoomNumber){
        return "North";
    }else{
        return "Unknown";
    }
}


