#include "Player.h"
#include "Room.h"

Player::Player(int x, int y) {
    this->x = x;
    this->y = y;
}

int Player::getX() const {
    return this->x;
}

int Player::getY() const {
    return this->y;
}

bool Player::move(char key, const Room& room) {
    int nextX = this->x;
    int nextY = this->y;

    if(key == 'w') {
        nextY--;
    } else if(key == 'a') {
        nextX--;
    } else if(key == 's') {
        nextY++;
    } else if(key == 'd') {
        nextX++;
    } else {
        return false;
    }

    // Keep current position if next space is a wall.
    if(room.isWall(nextX, nextY)) {
        return false;
    }

    this->x = nextX;
    this->y = nextY;
    return true;
}