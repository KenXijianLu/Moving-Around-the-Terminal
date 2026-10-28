#ifndef PLAYER_H
#define PLAYER_H

class Room;

class Player {
    private:
        int x;
        int y;

    public:
        Player(int x, int y);
        int getX() const;
        int getY() const;
        bool move(char key, const Room& room);
};

#endif
