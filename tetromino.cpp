#include "tetromino.h"

const int COLS = 10;

Tetromino::Tetromino(char s) : symbol(s) {
    blocks = {
        {0, 4}, {1, 4}, {2, 4}, {3, 4}
    };
}

const std::vector<Point>& Tetromino::getBlocks() const {
    return blocks;
}

void Tetromino::moveDown() {
    for (auto& block : blocks) {
        block.x += 1;
    }
}

void Tetromino::moveLeft() {
    for (auto& block : blocks) {
        block.y -= 1;
    }
}

void Tetromino::moveRight() {
    for (auto& block : blocks) {
        block.y += 1;
    }
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
