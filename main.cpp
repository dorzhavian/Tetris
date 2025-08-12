#include "board.h"
#include "tetromino.h"
#include <thread>
#include <chrono>
#include <conio.h>
#include <iostream>

static void waitForEnter() {
    while (_kbhit()) _getch();
    int ch;
    do { ch = _getch(); } while (ch != 13);
}

int main() {
    Board board;
    Tetromino t;

    if (!board.canPlace(t)) {
        system("cls");
        std::cout << "Game Over! Press Enter to exit...\n";
        waitForEnter();
        return 0;
    }

    int tick = 0;
    bool gameOver = false;

    while (!gameOver) {
        Board tempBoard = board;
        tempBoard.placeTetromino(t);
        tempBoard.draw();

        if (_kbhit()) {
            int key = _getch();
            if (key == 0 || key == 224) key = _getch();

            if (key == 75 && board.canMove(t, 0, -1)) t.moveLeft();
            else if (key == 77 && board.canMove(t, 0, 1)) t.moveRight();
            else if (key == 80 && board.canMove(t, 1, 0)) t.moveDown();
            else if (key == 72) {
                if (t.canRotate()) {
                    t.rotate();
                    if (!board.canPlace(t)) { t.rotate(); t.rotate(); t.rotate(); }
                }
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        tick++;

        if (tick == 5) {
            tick = 0;
            if (board.canMove(t, 1, 0)) {
                t.moveDown();
            }
            else {
                board.mergeTetromino(t);
                board.clearFullLines();
                t = Tetromino();
                if (!board.canPlace(t)) {
                    gameOver = true;
                }
            }
        }
    }

    system("cls");
    board.draw();
    std::cout << "Game Over! Press Enter to exit...\n";
    waitForEnter();
    return 0;
}