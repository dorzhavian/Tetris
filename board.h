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
    bool isCollision(const Tetromino& t) const;
    void mergeTetromino(const Tetromino& t);

    bool canPlace(const Tetromino& t) const;
    bool canMove(const Tetromino& t, int dx, int dy) const;
};
