#include <iostream>

void solution() {
    // Declare an integer variable and initialize it
    int myVar = 10;

    // Declare a pointer and make it point to this integer variable
    int* ptr = &myVar;

    // Semantic Error: Attempting to assign an integer literal (25) directly to an integer pointer (ptr).
    // This is a type mismatch; a pointer expects an address, not a value.
    ptr = 25;

    // Print both the new value of the integer variable and its memory address
    // Note: If the above line caused a compilation error, these lines would not execute.
    // If it were somehow allowed (e.g., via a cast), 'ptr' would no longer point to 'myVar'.
    std::cout << "New value of myVar: " << myVar << std::endl;
    std::cout << "Address of myVar: " << ptr << std::endl;
}

int main() {
    solution();
    return 0;
}