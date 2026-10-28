#ifndef ROOM_H
#define ROOM_H

class Room {
    private:
        int width;
        int height;
        char ** map;

    public:
        Room(int x, int y);
        ~Room();
        bool isWall(int x, int y) const;
        void draw(int playerX, int playerY) const;
};

#endif