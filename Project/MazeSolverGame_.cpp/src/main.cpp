#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "../include/maze_solver.h"  // Include the header file

using namespace std;

void displayMaze(const vector<vector<int> >& maze, int playerRow, int playerCol) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == playerRow && j == playerCol) {
                cout << "P "; // Player's position
            } else if (maze[i][j] == 1) {
                cout << "# "; // Wall
            } else {
                cout << ". "; // Path
            }
        }
        cout << endl;
    }
}

void generateMaze(vector<vector<int> >& maze) {
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = (rand() % 3 == 0) ? 1 : 0;
        }
    }
    maze[0][0] = 0;
    maze[ROWS - 1][COLS - 1] = 0;
}

bool solveMazeDFS(vector<vector<int> >& maze, int row, int col, vector<vector<bool> >& visited) {
    if (row == ROWS - 1 && col == COLS - 1) return true;
    if (row < 0 || col < 0 || row >= ROWS || col >= COLS || maze[row][col] == 1 || visited[row][col]) return false;

    visited[row][col] = true;

    if (solveMazeDFS(maze, row + 1, col, visited) || solveMazeDFS(maze, row - 1, col, visited) ||
        solveMazeDFS(maze, row, col + 1, visited) || solveMazeDFS(maze, row, col - 1, visited)) {
        return true;
    }

    visited[row][col] = false;
    return false;
}

void playMazeGame() {
    vector<vector<int> > maze(ROWS, vector<int>(COLS, 0));
    generateMaze(maze);

    int playerRow = 0, playerCol = 0;
    char move;
    cout << "Maze generated! Use 'W' (up), 'S' (down), 'A' (left), 'D' (right) to navigate.\n";
    
    while (true) {
        displayMaze(maze, playerRow, playerCol);
        if (playerRow == ROWS - 1 && playerCol == COLS - 1) {
            cout << "Congratulations! You have reached the exit.\n";
            break;
        }

        cout << "Move: ";
        cin >> move;

        int newRow = playerRow, newCol = playerCol;
        if (move == 'W' || move == 'w') newRow--;
        else if (move == 'S' || move == 's') newRow++;
        else if (move == 'A' || move == 'a') newCol--;
        else if (move == 'D' || move == 'd') newCol++;

        if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && maze[newRow][newCol] == 0) {
            playerRow = newRow;
            playerCol = newCol;
        } else {
            cout << "Invalid move!\n";
        }
    }
}

int main() {
    playMazeGame();
    return 0;
}
