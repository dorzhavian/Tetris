#pragma once

const int ROWS = 20;
const int COLS = 10;

class Board {
private:
    char grid[ROWS][COLS];
public:
    Board();
    void draw();
};