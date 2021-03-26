#include <iostream>
#include <string>


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

#define NUMBER_CARDS_TO_READ 5

void printColourAsString(int colour);
void printCard(int number, int colour);

// void readOneCard(int* number, int* colour);
void readOneCard(int& number, int& colour);

int main(void) {
   int number[NUMBER_CARDS_TO_READ] = {};
   int colour[NUMBER_CARDS_TO_READ] = {};

   int numReads = 0;
   // Read until EOF
   while(!std::cin.eof() && numReads < NUMBER_CARDS_TO_READ) {
      // Read the card value
      // int tmpNumber = 0;
      // int tmpColour = 0;
      // readOneCard(&tmpNumber, &tmpColour);

      // number[numReads] = tmpNumber;
      // colour[numReads] = tmpColour;

      // readOneCard(&number[numReads], &colour[numReads]);
      readOneCard(number[numReads], colour[numReads]);
      
      // Print out "natural version" of the card
      if(!std::cin.eof()){
         ++numReads;
      }
   }

   for(int i=0; i < numReads && i < NUMBER_CARDS_TO_READ; ++i){
      printCard(number[i], colour[i]);
   }

   return EXIT_SUCCESS;
}

// void readOneCard(int* number, int* colour){
//    std::cin >> colour;
//    std::cin >> number;
// }

void readOneCard(int& number, int& colour){
   std::cin >> colour;
   std::cin >> number;
}

void printCard(int number, int colour){

   std::cout << "Red7 Card : ";
      printColourAsString(colour);
      std::cout << " - " << number << std::endl;
}

void printColourAsString(int colour) {
   // Define some colours as string
   char red[] = "Red";
   char orange[] = "Orange";
   char yellow[] = "Yellow";
   char green[] = "Green";
   char blue[] = "Blue";
   char indigo[] = "Indigo";
   char violet[] = "Violet";
   char unknown[] = "UNKNOWN";

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

}
