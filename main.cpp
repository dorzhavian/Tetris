#include "board.h"
#include "tetromino.h"
#include <thread>
#include <chrono>
#include <conio.h>

int main() {
    Board board;
    Tetromino t;

    int tick = 0;

    while (true) {
        board.clear();
        board.placeTetromino(t);
        board.draw();

        if (_kbhit()) {
            char key = _getch();
            if (key == 75 && t.canMoveLeft()) t.moveLeft();
            if (key == 77 && t.canMoveRight()) t.moveRight();
            if (key == 80) t.moveDown();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        tick += 1;

        if (tick == 5) {
            tick = 0;

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
    }

    return 0;
}
