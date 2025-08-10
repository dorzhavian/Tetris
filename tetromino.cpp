#include "tetromino.h"

const int COLS = 10;
const int ROWS = 20;

Tetromino::Tetromino(char s) : symbol(s) {
    blocks = {
        {0, 4}, {1, 4}, {2, 4}, {3, 4}
    };
}

const std::vector<Point>& Tetromino::getBlocks() const {
    return blocks;
}

void Tetromino::moveDown() {
    for (auto& block : blocks) block.x += 1;
}

void Tetromino::moveLeft() {
    for (auto& block : blocks) block.y -= 1;
}

void Tetromino::moveRight() {
    for (auto& block : blocks) block.y += 1;
}

bool Tetromino::canMoveLeft() const {
    for (const auto& block : blocks) {
        if (block.y - 1 < 0) return false;
    }
    return true;
}

bool Tetromino::canMoveRight() const {
    for (const auto& block : blocks) {
        if (block.y + 1 >= COLS) return false;
    }
    return true;
}

void Tetromino::rotate() {
    Point pivot = blocks[1]; // center for I-block
    for (auto& block : blocks) {
        int relX = block.x - pivot.x;
        int relY = block.y - pivot.y;
        block.x = pivot.x - relY;
        block.y = pivot.y + relX;
    }
}

bool Tetromino::canRotate() const {
    Point pivot = blocks[1];
    for (const auto& block : blocks) {
        int relX = block.x - pivot.x;
        int relY = block.y - pivot.y;
        int newX = pivot.x - relY;
        int newY = pivot.y + relX;
        if (newX < 0 || newX >= ROWS || newY < 0 || newY >= COLS) return false;
    }
    return true;
}