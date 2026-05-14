#include <iostream>

void solution() {
    // Declare an integer variable and initialize it
    int myVar = 10;

    // Declare a pointer and make it point to this integer variable
    int* ptr = &myVar;

    // Using only the pointer, modify the value of the integer variable
    *ptr = 25 // Syntax Error: Missing semicolon here

    // Print both the new value of the integer variable and its memory address
    std::cout << "New value of myVar: " << myVar << std::endl;
    std::cout << "Address of myVar: " << ptr << std::endl;
}

int main() {
    solution();
    return 0;
}