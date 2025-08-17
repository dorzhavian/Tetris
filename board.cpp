#include "board.h"
#include <iostream>
using namespace std;

Board::Board() {
    clear();
    score = 0;
}

void Board::clear() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = ' ';
        }
    }
}

void Board::draw() {
    system("cls");
    cout << "Score: " << score << "\n\n";
    for (int i = 0; i < ROWS; i++) {
        cout << "|";
        for (int j = 0; j < COLS; j++) {
            cout << grid[i][j];
        }
        cout << "|\n";
    }
    cout << "+";
    for (int j = 0; j < COLS; j++) cout << "-";
    cout << "+\n";
}

void Board::placeTetromino(const Tetromino& t) {
    for (auto& block : t.getBlocks()) {
        if (block.x >= 0 && block.x < ROWS && block.y >= 0 && block.y < COLS) {
            grid[block.x][block.y] = '#';
        }
    }
}

bool Board::isCollision(const Tetromino& t) const {
    for (auto& block : t.getBlocks()) {
        if (block.x + 1 >= ROWS) return true;
        if (block.x + 1 >= 0 && block.y >= 0 && block.y < COLS) {
            if (grid[block.x + 1][block.y] == '#') return true;
        }
    }
    return false;
}

void Board::mergeTetromino(const Tetromino& t) {
    for (auto& block : t.getBlocks()) {
        if (block.x >= 0 && block.x < ROWS && block.y >= 0 && block.y < COLS) {
            grid[block.x][block.y] = '#';
        }
    }
}

bool Board::canPlace(const Tetromino& t) const {
    for (auto& block : t.getBlocks()) {
        if (block.x < 0 || block.x >= ROWS || block.y < 0 || block.y >= COLS) return false;
        if (grid[block.x][block.y] == '#') return false;
    }
    return true;
}

bool Board::canMove(const Tetromino& t, int dx, int dy) const {
    for (auto& block : t.getBlocks()) {
        int nx = block.x + dx;
        int ny = block.y + dy;
        if (nx < 0 || nx >= ROWS || ny < 0 || ny >= COLS) return false;
        if (grid[nx][ny] == '#') return false;
    }
    return true;
}

int Board::clearFullLines() {
    int cleared = 0;
    for (int r = ROWS - 1; r >= 0; --r) {
        bool full = true;
        for (int c = 0; c < COLS; ++c) {
            if (grid[r][c] != '#') { full = false; break; }
        }
        if (full) {
            ++cleared;
            for (int rr = r; rr > 0; --rr) {
                for (int c = 0; c < COLS; ++c) {
                    grid[rr][c] = grid[rr - 1][c];
                }
            }
            for (int c = 0; c < COLS; ++c) grid[0][c] = ' ';
            r++;
        }
    }
    return cleared;
}

int Board::getScore() const {
    return score;
}

void Board::addScore(int lines) {
    if (lines == 1) score += 100;
    else if (lines == 2) score += 300;
    else if (lines == 3) score += 500;
    else if (lines == 4) score += 800;
}