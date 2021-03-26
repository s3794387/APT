#include <iostream>

#define ROWS 10
#define COLS 5

int main(void) {

    int x = 10;
    int y = -3;

    int* ptr = &x;
    int* qtr = &y;

    std::cout << x << std::endl;
    std::cout << y << std::endl;

    std::cout << *ptr << std::endl;
    std::cout << *qtr << std::endl;

    //Addresses
    std::cout << ptr << std::endl;
    std::cout << qtr << std::endl;

    x = y;
    std::cout << *ptr << std::endl;
    std::cout << *qtr << std::endl;

    *qtr = -42;
    std::cout << *ptr << std::endl;
    std::cout << *qtr << std::endl;

    int** pptr = &ptr;
    int** qqtr = &qtr;

    //memory address of a pointer ptr/qtr
    std::cout << pptr << std::endl;
    std::cout << qqtr << std::endl;

    //memory address of x/y
    std::cout << *pptr << std::endl;
    std::cout << *qqtr << std::endl;

    //vlaues of x/y
    std::cout << **pptr << std::endl;
    std::cout << **qqtr << std::endl;

    //pointer to no where
    ptr = nullptr;

    //dereference nullptr
    std::cout << *ptr << std::endl;

    return EXIT_SUCCESS;
}
