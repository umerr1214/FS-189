#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    // Declare a double variable and initialize it with a decimal value
    double myValue = 123.456789;

    // Declare a void pointer to the double variable.
    // This loses type information, which can be a robustness issue in more complex scenarios.
    void* voidPtr = &myValue;

    // Print the value of the variable using dereferencing the pointer.
    // Requires explicit casting from void* back to double*.
    std::cout << "Value: " << std::fixed << std::setprecision(6) << *(static_cast<double*>(voidPtr)) << std::endl;

    // Print the memory address of the variable using the address-of operator
    std::cout << "Address (using &): " << &myValue << std::endl;

    // Print the memory address of the variable using the pointer itself
    std::cout << "Address (using pointer): " << voidPtr << std::endl;

    return 0;
}