#include "tetromino.h"

Tetromino::Tetromino(char s) : symbol(s) {
    // I-block shape (vertical at top)
    blocks = {
        {0, 4}, {1, 4}, {2, 4}, {3, 4}
    };
}

const std::vector<Point>& Tetromino::getBlocks() const {
    return blocks;
}
