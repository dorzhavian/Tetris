# Tetris (C++ ASCII Version)

## Description
This is a simple Tetris game written in C++ that runs in the console using ASCII characters.  
It was built as a practice project to improve my C++ skills and learn how to handle game logic, input, and rendering in the terminal.

---

## Features
- Playable Tetris in the console  
- Moving and rotating blocks  
- Line clearing and scoring  
- Game Over screen (waits for Enter before exit)

---

## How to Run
1. Clone the repo:
   ```bash
   git clone https://github.com/dorzhavian/Tetris.git
   cd Tetris
   ```
2. Compile:
  ```bash
  g++ main.cpp board.cpp -o tetris
  ```
3.Run:
  ```bash
  ./tetris
  ```

## Controls

| Key        | Action                       |
|------------|------------------------------|
| Left/Right | Move block left/right        |
| Up         | Rotate block                 |
| Down       | Drop faster                  |
| Space      | Hard drop (instant place)    |
| Enter      | Confirm exit after Game Over |

## Contributing ##
Pull requests are welcome!
Please keep the code portable (standard C++17) and avoid platform‑specific APIs unless guarded by #ifdef.
