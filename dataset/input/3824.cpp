#include <iostream>

int main() {
    // Allocate memory for an array of 5 integers
    int* a = new int[5]; // Non-descriptive variable name 'a'
    const int S = 5;     // Non-descriptive constant name 'S'

    std::cout << "Please enter " << S << " integer values:\n"; // Magic number 5 repeated implicitly

    // Loop to get input
    for (int i = 0; i < 5; ++i) { // Magic number 5 repeated
        std::cout << "Enter value for element " << i + 1 << ": ";
        std::cin >> a[i]; // Input handled without validation (not the primary error here, but contributes to quality)
    }

    std::cout << "The values you entered are:\n";

    // Loop to print values
    for (int j = 0; j < S; ++j) { // Another non-descriptive variable name 'j'
        std::cout << "Value at index " << j << ": " << a[j] << "\n";
    }

    // Deallocate memory
    delete[] a;
    a = NULL; // Using NULL instead of nullptr, which is less modern C++

    return 0;
}