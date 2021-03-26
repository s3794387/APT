
#include <iostream>

#define ROWS   4
#define COLS   5

void readMaze(char maze[ROWS][COLS]);
void printMaze(char maze[ROWS][COLS]);

int main (void) {
   char maze[ROWS][COLS] = {};

   readMaze(maze);
   printMaze(maze);

   return EXIT_SUCCESS;
}

void readMaze(char maze[ROWS][COLS]) {
   // TODO
   maze[0][0] = '?';
}

void printMaze(char maze[ROWS][COLS]) {
   for (int row = 0; row < ROWS; ++row){
      for (int col = 0; col < COLS; ++col){
         std::cout << maze[row][col];
      }
      std::cout << std::endl;
   }
}