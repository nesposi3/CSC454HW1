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

void Room::setState(int x) {
    this->state =x;
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
int Room::getNumCreatures(){
    return this->numCreatures;
}
void Room::printString(){
     cout << "Room no. " << this->num << " North: " << this->north << " South: " << this->south << " East: " << this->east << " West " << this->west;
}