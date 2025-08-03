#pragma once
#include <vector>

struct Point {
    int x, y;
};

class Tetromino {
private:
    std::vector<Point> blocks;
    char symbol;
public:
    Tetromino(char s = '#');
    const std::vector<Point>& getBlocks() const;
    void moveDown();
};