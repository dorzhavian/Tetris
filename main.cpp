#include "board.h"
#include "tetromino.h"
#include <thread>
#include <chrono>

int main() {
    Board board;
    Tetromino t;

    while (true) {
        board.clear();
        board.placeTetromino(t);
        board.draw();

        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        // stop if tetromino hits the bottom
        bool atBottom = false;
        for (auto& block : t.getBlocks()) {
            if (block.x + 1 >= ROWS) {
                atBottom = true;
                break;
            }
        }

        if (atBottom) break;

        t.moveDown();
    }

    return 0;
}