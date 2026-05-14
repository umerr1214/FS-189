#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

int main() {
    // Declare a double variable and initialize it with a decimal value
    double myDoubleVariable = 3.1415926535;

    // Declare a pointer to that variable
    double* ptrToDouble = &myDoubleVariable;

    // Print the value of the variable using dereferencing the pointer
    // Using std::fixed and std::setprecision for precise and clear output of double.
    std::cout << "Value: " << std::fixed << std::setprecision(10) << *ptrToDouble << std::endl;

    // Print the memory address of the variable using the address-of operator
    // Directly printing the address-of operator result with std::cout is idiomatic.
    std::cout << "Address (using &): " << &myDoubleVariable << std::endl;

    // Print the memory address of the variable using the pointer itself
    // Directly printing the pointer with std::cout is idiomatic.
    std::cout << "Address (using pointer): " << ptrToDouble << std::endl;

    return 0;
}