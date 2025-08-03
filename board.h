#pragma once
#include "tetromino.h"

const int ROWS = 20;
const int COLS = 10;

class Board {
private:
    char grid[ROWS][COLS];
public:
    Board();
    void clear();
    void draw();
    void placeTetromino(const Tetromino& t);
};