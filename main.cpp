#include "board.h"
#include "tetromino.h"

int main() {
    Board board;
    Tetromino t;

    board.placeTetromino(t);
    board.draw();

    return 0;
}