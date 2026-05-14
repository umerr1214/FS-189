#include <iostream>
#include <cstdio> // Required for printf

int main() {
    double val; // Less descriptive variable name
    
    std::cout << "Enter monetary value: ";
    std::cin >> val;

    // Readability/Efficiency issue: Using C-style printf for formatting instead of C++ iostream manipulators
    printf("$%.2f\n", val); 

    return 0;
}