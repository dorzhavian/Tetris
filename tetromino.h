#pragma once
#include <vector>
#include <random>

struct Point {
    int x, y;
};

enum TetrominoType { I, O, T, L, J, S, Z };

class Tetromino {
private:
    std::vector<Point> blocks;
    char symbol;
    TetrominoType type;
public:
    Tetromino();
    const std::vector<Point>& getBlocks() const;
    void moveDown();
    void moveLeft();
    void moveRight();
    bool canMoveLeft() const;
    bool canMoveRight() const;
    void rotate();
    bool canRotate() const;
    TetrominoType getType() const { return type; }
    char getSymbol() const { return symbol; }
};