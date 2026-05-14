#include <iostream> // Required for std::cout and std::endl
#include <iomanip>  // Required for std::hex and std::showbase

int main() {
    int myVar; // Robustness issue: myVar is declared but NOT initialized.
               // Reading its value leads to undefined behavior.

    int* ptr = &myVar; // Pointer correctly points to myVar's memory location.

    // Print the value of the variable. This reads uninitialized memory, leading to UB.
    std::cout << "Value of variable: " << myVar << std::endl;

    // Print the value accessed through the pointer. This also reads uninitialized memory, leading to UB.
    std::cout << "Value accessed through pointer: " << *ptr << std::endl;

    // Print the address of the variable. The address itself is valid.
    std::cout << "Address of variable: " << std::showbase << std::hex << &myVar << std::endl;

    // Print the address stored in the pointer. This is the same valid address.
    std::cout << "Address stored in pointer: " << std::showbase << std::hex << ptr << std::endl;

    return 0;
}