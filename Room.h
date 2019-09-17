//
// Created by nick on 9/1/19.
//

#ifndef HOMEWORK1_ROOM_H
#define HOMEWORK1_ROOM_H


#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
using namespace std;
class Room{
public:

    Room(int st, int no,int so, int ea, int we, int num );
    int getState();
    int getNum();
    int getNorth();
    int getSouth();
    int getEast();
    int getWest();
    int getNumCreatures();
    string toString();
    void addCreature();
    void removeCreature();
    bool clean();
    bool dirty();
    bool hasNeighbors();
    bool isFull();
    bool hasAvailableNeighbors(Room ** rooomList);
    int getRandomNeighbor();
    vector<int> getNeighbors();
    void setState(int num);
private:
    int state;
    int num;
    int north ;
    int south ;
    int east ;
    int west ;
    int numCreatures;
};



#endif //HOMEWORK1_ROOM_H
