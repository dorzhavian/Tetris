#include "tetromino.h"

const int COLS = 10;
const int ROWS = 20;

Tetromino::Tetromino() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 6);
    type = static_cast<TetrominoType>(dist(gen));

    switch (type) {
    case I:
        symbol = '#';
        blocks = { {0,4}, {1,4}, {2,4}, {3,4} };
        break;
    case O:
        symbol = 'O';
        blocks = { {0,4}, {0,5}, {1,4}, {1,5} };
        break;
    case T:
        symbol = 'T';
        blocks = { {0,4}, {1,3}, {1,4}, {1,5} };
        break;
    case L:
        symbol = 'L';
        blocks = { {0,4}, {1,4}, {2,4}, {2,5} };
        break;
    case J:
        symbol = 'J';
        blocks = { {0,4}, {1,4}, {2,4}, {2,3} };
        break;
    case S:
        symbol = 'S';
        blocks = { {0,5}, {0,4}, {1,4}, {1,3} };
        break;
    case Z:
        symbol = 'Z';
        blocks = { {0,3}, {0,4}, {1,4}, {1,5} };
        break;
    }
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
    if (type == O) return; // square doesn't rotate
    Point pivot = blocks[1];
    for (auto& block : blocks) {
        int relX = block.x - pivot.x;
        int relY = block.y - pivot.y;
        block.x = pivot.x - relY;
        block.y = pivot.y + relX;
    }
}

bool Tetromino::canRotate() const {
    if (type == O) return false;
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