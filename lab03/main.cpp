#include <iostream>
#include "Example.h"

#define EXIT_SUCCESS    0
#define LENGTH          10

int main (void) {

   Example* example = new Example(7.5);
   
   double dbl = 45;

   //example->setValue(dbl);
   (*example).setValue(dbl);


   std::cout << example->getValue() << std::endl;

   return EXIT_SUCCESS;
}