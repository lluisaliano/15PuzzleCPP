# 15 Puzzle in C++

A terminal based implementation of the classic 15 Puzzle written in C++.

The program generates a solvable 4x4 puzzle, renders in the terminal, and lets the player move tiles with single key press until the board is solved or the player quits.

## Features

- Written in C++23 with a small, focused object-oriented design.
- Uses CMake for the build system.
- Randomizes the puzzle by applying valid moves from the solved state, which guarantees a solvable board.
- Uses non canonical terminal flag, so moves are read instantly without pressing Enter.
- Centers the board and messages in the terminal for a cleaner text UI.

  ![15Puzzle](https://github.com/user-attachments/assets/b6bdd096-7b3e-43a8-a486-f4b54748f58c)

## How It Works

The project models the puzzle with a few small classes:

- `Board`: owns the 4x4 grid, applies moves, checks the solved state, and randomizes the puzzle.
- `Tile`: represents a numbered tile, including the empty tile.
- `Point`: stores grid coordinates and computes adjacent positions.
- `Direction`: represents movement directions and provides random direction generation.
- `UserInput` / `UserOutput`: handle terminal interaction, screen clearing, centered output, and single-character input.

At startup, the board begins in the solved state and is shuffled through repeated valid moves. This avoids generating impossible puzzle configurations.

## Controls

- `w`: move up
- `a`: move left
- `s`: move down
- `d`: move right
- `q`: quit the game

## Build

This project is currently configured for:

- C++23
- CMake
- A Unix-like terminal environment (As it uses POSIX API)

Configure and build:

```bash
cmake -S . -B build
cmake --build build
```

## Run

```bash
./build/15Puzzle
```

## Project Structure

```text
.
├── CMakeLists.txt
├── include/
│   ├── Board.hpp
│   ├── Direction.hpp
│   ├── Point.hpp
│   ├── Random.hpp
│   ├── Tile.hpp
│   ├── UserInput.hpp
│   └── UserOutput.hpp
└── src/
    ├── Board.cpp
    ├── Direcion.cpp
    ├── Point.cpp
    ├── Tile.cpp
    └── main.cpp
```
