#ifndef MAZE_SOLVER_H
#define MAZE_SOLVER_H

#include <vector>

// Constants for maze dimensions
const int ROWS = 5;
const int COLS = 5;

// Function declarations
void displayMaze(const std::vector<std::vector<int> >& maze, int playerRow, int playerCol);
void generateMaze(std::vector<std::vector<int> >& maze);
bool solveMazeDFS(std::vector<std::vector<int> >& maze, int row, int col, std::vector<std::vector<bool> >& visited);
void playMazeGame();

#endif

