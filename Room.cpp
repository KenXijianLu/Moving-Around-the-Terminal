#include "Room.h"
#include <iostream>

using namespace std;

Room::Room(int x, int y) {
    this->width = x;
    this->height = y;

    // Allocates the row pointers then each row of characters.
    this->map = new char*[this->height];

    for(int outerCounter = 0; outerCounter < this->height; outerCounter++) {
        this->map[outerCounter] = new char[this->width];

        for(int innerCounter = 0; innerCounter < this->width; innerCounter++) {
            if(outerCounter == 0 || outerCounter == this->height - 1 ||
               innerCounter == 0 || innerCounter == this->width - 1) {
                this->map[outerCounter][innerCounter] = '#';
            } else {
                this->map[outerCounter][innerCounter] = ' ';
            }
        }
    }

    // Adds inner walls, leaving open paths and the starting space.
    for(int outerCounter = 2; outerCounter < this->height - 1; outerCounter += 2) {
        for(int innerCounter = 2; innerCounter < this->width - 1; innerCounter += 3) {
            this->map[outerCounter][innerCounter] = '#';
        }
    }
}

Room::~Room() {
    // Delete the rows before deleting the array of row pointers.
    for(int outerCounter = 0; outerCounter < this->height; outerCounter++) {
        delete[] this->map[outerCounter];
    }

    delete[] this->map;
}

bool Room::isWall(int x, int y) const {
    if(x < 0 || x >= this->width || y < 0 || y >= this->height) {
        return true;
    }

    return this->map[y][x] == '#';
}

void Room::draw(int playerX, int playerY) const {
    cout << endl;

    for(int outerCounter = 0; outerCounter < this->height; outerCounter++) {
        for(int innerCounter = 0; innerCounter < this->width; innerCounter++) {
            if(innerCounter == playerX && outerCounter == playerY) {
                cout << '@';
            } else {
                cout << this->map[outerCounter][innerCounter];
            }
        }

        cout << endl;
    }
}