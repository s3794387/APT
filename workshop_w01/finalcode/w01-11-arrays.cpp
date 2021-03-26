
#include <cstdio>
#include <iostream>

#define LENGTH          10
#define ROWS            10
#define COLS            5

void printArray(int* array, int length);
// void printArray2D(int** array, int rows, int cols);

void printString(char* string);

int main (void) {

   int a[LENGTH] = {1};
   printArray(a, LENGTH);

   std::cout << a << std::endl;

   int* b = a;
   std::cout << b << std::endl;
   std::cout << a << std::endl;

   char string[LENGTH] = "hello";
   printString(string);

   // int b[LENGTH] = {1, 2, 3, 4};
   // printArray(b, LENGTH);

   // int twoD[ROWS][COLS];
   // int counter = 100;
   // for (int row = 0; row < ROWS; ++row) {
   //    for (int column = 0; column < COLS; ++column) {
   //       twoD[row][column] = counter;
   //       ++counter;
   //    }
   // }
   // printArray2D(twoD, ROWS, COLS);

   return EXIT_SUCCESS;
}

void printArray(int* array, int length) {
   for (int i = 0; i < length; ++i) {
      std::cout << "array[" << i << "] = " << array[i] << std::endl;
   }
   std::cout << std::endl;
}

void printString(char* string) {
   std::cout << string << std::endl;
}

// void printArray2D(int** array, int rows, int cols) {
//    // Print
//    for (int row = 0; row < rows; ++row) {
//       for (int column = 0; column < cols; ++column) {
//          std::cout << array[row][column] << " ";
//       }
//       std::cout << std::endl;
//    }
// }