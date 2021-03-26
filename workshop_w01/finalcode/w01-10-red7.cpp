#include <iostream>
#include <string>

/**
 * Topics:
 * 
 * 1. The basics:
 *  - comments 
 *  - data types (int/float/double/string)
 *  - operators
 *  - if/else
 *  - while/for
 * 2. Differences:
 *  - strings
 *  - read / write / endl
 *  - Declarations (#defines) & Compiler process - see slide
 * 3. Concepts:
 *  - Types & Typecasting
 *  - Declaration / Definition / Initialisation
 * 4. More differences:
 *  - Functions - parameter passing
 *  - Arrays
 *  - Namespace
 *  - Global Variables
 */

#define RED    0
#define ORANGE 1
#define YELLOW 2
#define GREEN  3
#define BLUE   4
#define INDIGO 5
#define VIOLET 6

// #define RED    'r'
// #define ORANGE 'o'
// #define YELLOW 'y'
// #define GREEN  'g'
// #define BLUE   'b'
// #define INDIGO 'i'
// #define VIOLET 'v'

#define NUMS_FROM_USER 3

void printColourAsString(int colour);

int main(void) {
   // this is the first line of code that gets run

   int number = 7;
   int colour = BLUE;

   std::cout << "Red7 Card " << std::endl;
   std::cout << "\tnumber: " << number << std::endl;
   printColourAsString(colour);
   

   // for (int i = 0; i < NUMS_FROM_USER; ++i) {
   // Keep going until we type ^D (ctrl-d)
   while (!std::cin.eof()) {
      std::cin >> number;
      std::cin >> colour;
      std::cout << "Red7 Card - read from the user" << std::endl;
      std::cout << "\tnumber: " << number << std::endl;
      printColourAsString(colour);
   }

   return EXIT_SUCCESS;
}

void printColourAsString(int colour) {
   // Define some colours as string
   std::string red = "Red";
   std::string orange = "Orange";
   std::string yellow = "Yellow";
   std::string green = "Green";
   std::string blue = "Blue";
   std::string indigo = "Indigo";
   std::string violet = "Violet";
   std::string unknown = "UNKNOWN";

   std::cout << "\tcolour: ";
   if (colour == RED) {
      std::cout << red;
   } else if (colour == ORANGE) {
      std::cout << orange;
   } else if (colour == YELLOW) {
      std::cout << yellow;
   } else if (colour == GREEN) {
      std::cout << green;
   } else if (colour == BLUE) {
      std::cout << blue;
   } else if (colour == INDIGO) {
      std::cout << indigo;
   } else if (colour == VIOLET) {
      std::cout << violet;
   } else {
      std::cout << unknown;
   }
   std::cout << std::endl;
}
