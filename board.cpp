#include "board.h"
#include <iostream>
using namespace std;

Board::Board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = ' ';
        }
    }
}

void Board::draw() {
    system("cls"); // use "clear" on Linux/Mac
    for (int i = 0; i < ROWS; i++) {
        cout << "|";
        for (int j = 0; j < COLS; j++) {
            cout << grid[i][j];
        }
        cout << "|\n";
    }

    cout << "+";
    for (int j = 0; j < COLS; j++) cout << "-";
    cout << "+\n";
}