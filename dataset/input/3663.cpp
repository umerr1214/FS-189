#include <iostream> // Required for std::cout and std::endl
#include <iomanip>  // Required for std::hex and std::showbase

int main() {
    // Declare an integer variable and initialize it
    int myIntegerVariable = 100;

    // Declare a pointer to the integer variable and initialize it
    int* pointerToMyInteger = &myIntegerVariable;

    // Print the value of the variable
    std::cout << "Value of myIntegerVariable: " << myIntegerVariable << std::endl;

    // Print the value accessed through the pointer
    std::cout << "Value accessed through pointerToMyInteger: " << *pointerToMyInteger << std::endl;

    // Print the address of the variable, formatted as hexadecimal with a base prefix
    std::cout << "Address of myIntegerVariable: " << std::showbase << std::hex << &myIntegerVariable << std::endl;

    // Print the address stored in the pointer, formatted as hexadecimal with a base prefix
    // This should be the same as the address of the variable
    std::cout << "Address stored in pointerToMyInteger: " << std::showbase << std::hex << pointerToMyInteger << std::endl;

    return 0;
}