Project Report
(Design & Analysis Of Algorithms)
Instructor
Mr. Usman Sharif
BS ( CS )
Project Title: Maze Solver Game - Official Project Report
Group Members
• Muhammad Bilal (45775)
• Hammad Ahmed (46391)
• Muhammad Taha (54592)
• Umair Waseem (44296)
1. Introduction
The Maze Solver Game is a console-based game created in C++ to illustrate depth-first search (DFS)
and backtracking algorithms. This project, developed as part of our Design and Analysis of
Algorithms (DAA) course, provides an interactive and educational way to explore algorithmic
principles through a game. The objective is for the player to navigate from the start to the end of a
randomly generated maze while avoiding obstacles.
2. Objectives
The primary objectives of this project are to:
• Demonstrate DFS and Backtracking: Implement DFS to find a path through a maze,
showcasing backtracking to handle dead ends.
• Visualize Algorithmic Complexity: Provide a hands-on approach to learning about algorithm
complexity through gameplay.
• Enhance Understanding of Pathfinding: Allow players to navigate a maze, reinforcing
concepts of algorithmic pathfinding and decision-making.
3. Requirements and Justification
• Programming Language: C++
o Justification: C++ is efficient for handling recursion and console-based I/O, both of
which are essential for this project.
• Algorithmic Concepts: Depth-First Search (DFS) and Backtracking
o Justification: DFS and backtracking are core concepts in DAA, commonly used for
exploring graphs and mazes.
4. Project Structure
1. MazeSolverGame/ (Root Folder):
o Contains all project files, keeping resources organized.
2. src/main.cpp:
o Contains the main game logic, including maze generation, DFS, and player movement.
3. include/maze_solver.h:
o Declares constants and function prototypes, improving code modularity.
4. build/:
o Stores the compiled executable file maze_game after building.
5. .vscode/tasks.json:
o Defines build and run tasks, automating compilation and execution within Visual
Studio Code.
5. Detailed Code Explanation
Each function in main.cpp is designed to implement a specific part of the game. Below is a
breakdown of each function, along with the reasoning for its implementation and its complexity.
displayMaze Function
Code:
cpp
Copy code
void displayMaze(const vector<vector<int> >& maze, int playerRow, int playerCol)
{
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
Explanation:
• This function displays the current state of the maze in the console.
• The player’s position is shown as P, walls are represented by #, and paths by ..
Complexity:
• Time Complexity: O(N), where N is the total number of cells. Each cell is accessed once per
display.
• Space Complexity: O(1), as it only displays the maze layout without storing additional data.
generateMaze Function
Code:
cpp
Copy code
void generateMaze(vector<vector<int> >& maze) {
srand(static_cast<unsigned int>(time(0)));
for (int i = 0; i < ROWS; i++) {
for (int j = 0; j < COLS; j++) {
maze[i][j] = (rand() % 3 == 0) ? 1 : 0; // 1 is wall, 0 is path
}
}
maze[0][0] = 0; // Start position
maze[ROWS - 1][COLS - 1] = 0; // End position
}
Explanation:
• Randomly generates walls and paths throughout the maze.
• Ensures that the start and end points are open paths to make the maze potentially solvable.
Complexity:
• Time Complexity: O(N), where N is the number of cells.
• Space Complexity: O(N), as it stores the maze grid.
solveMazeDFS Function
Code:
cpp
Copy code
bool solveMazeDFS(vector<vector<int> >& maze, int row, int col,
vector<vector<bool> >& visited) {
if (row == ROWS - 1 && col == COLS - 1) return true; // Exit found
if (row < 0 || col < 0 || row >= ROWS || col >= COLS || maze[row][col] == 1
|| visited[row][col]) return false;
visited[row][col] = true;
if (solveMazeDFS(maze, row + 1, col, visited) || solveMazeDFS(maze, row - 1,
col, visited) ||
- 1, visited)) {
return true;
solveMazeDFS(maze, row, col + 1, visited) || solveMazeDFS(maze, row, col
}
visited[row][col] = false; // Backtrack
return false;
}
Explanation:
• Uses DFS to find a path through the maze.
• Backtracking: If the current path fails, the algorithm backtracks to explore other options.
Complexity:
• Time Complexity: O(N), where N is the number of cells.
• Space Complexity: O(N) due to recursion stack and visited array.
playMazeGame Function
Code:
cpp
Copy code
void playMazeGame() {
vector<vector<int> > maze(ROWS, vector<int>(COLS, 0));
generateMaze(maze);
int playerRow = 0, playerCol = 0;
char move;
navigate.\n";
cout << "Maze generated! Use 'W' (up), 'S' (down), 'A' (left), 'D' (right) to
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
if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS &&
maze[newRow][newCol] == 0) {
playerRow = newRow;
playerCol = newCol;
} else {
cout << "Invalid move!\n";
}
}
}
Explanation:
• Main game loop allowing the player to move through the maze.
• Checks for valid moves and prevents the player from moving through walls.
Complexity:
• Time Complexity: Depends on player input but is effectively O(1) per move.
• Space Complexity: O(1), as it doesn’t create additional data structures.
6. Complexity Analysis
Maze Generation:
• Time Complexity: O(N) since each cell is initialized once.
• Space Complexity: O(N) for storing the maze grid.
DFS Pathfinding:
• Time Complexity: O(N) in the worst case, with each cell being visited once.
• Space Complexity: O(N) due to recursion stack and visited array.
7. Conclusion
The Maze Solver Game effectively demonstrates DFS and backtracking, making it a valuable
learning tool in our DAA course. By navigating a randomly generated maze, this project provides an
engaging way to understand algorithmic complexity and problem-solving strategies. It highlights the
efficiency and practicality of DFS for small grid-based problems, showcasing algorithmic principles
in an interactive format.
This report should cover all the required details, including code explan