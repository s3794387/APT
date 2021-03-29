
#include <iostream>

#define ROWS   4
#define COLS   5

typedef char Env[20][20];

void readMaze(Env env);
void printMaze(Env env);

int main (void) {
   Env env = {};

   readMaze(env);
   printMaze(env);

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