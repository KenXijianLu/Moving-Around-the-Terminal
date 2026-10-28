#include <iostream>
#include "Room.h"
#include "Player.h"

using namespace std;

int main() {
    int rows;
    int columns;

    cout << "Enter the number of rows: ";
    if(!(cin >> rows) || rows < 5) {
        cout << "Enter a whole number of at least 5." << endl;
        return 1;
    }

    cout << "Enter the number of columns: ";
    if(!(cin >> columns) || columns < 5) {
        cout << "Enter a whole number of at least 5." << endl;
        return 1;
    }

    // Width is the # of columns; height is the # of rows.
    Room room(columns, rows);
    Player player(1, 1);
    char key;
    bool isRunning = true;

    cout << "Use w, a, s, d to move. Enter q to quit." << endl;
    cout << "Press Enter after each key." << endl;
    room.draw(player.getX(), player.getY());

    while(isRunning) {
        cout << "Move: ";
        if(!(cin >> key)) {
            break;
        }

        if(key == 'q') {
            isRunning = false;
        } else {
            player.move(key, room);
            room.draw(player.getX(), player.getY());
        }
    }

    return 0;
}