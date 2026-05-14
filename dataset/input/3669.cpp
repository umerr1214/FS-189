#include <iostream>

void incrementValue(int* ptr) {
    // Correct version: Includes a nullptr check for robustness and uses
    // the idiomatic increment operator for clarity and efficiency.
    if (ptr == nullptr) {
        std::cerr << "Error: Cannot increment a null pointer." << std::endl;
        return; 
    }
    (*ptr)++; // Idiomatic and efficient way to increment the value pointed to
}

int main() {
    int number = 7;
    std::cout << "Initial value of number: " << number << std::endl;

    incrementValue(&number);
    std::cout << "Value of number after first increment: " << number << std::endl;

    incrementValue(&number);
    std::cout << "Value of number after second increment: " << number << std::endl;

    // Demonstrate robust handling of nullptr
    int* nullPtr = nullptr;
    std::cout << "\nAttempting to increment a null pointer:" << std::endl;
    incrementValue(nullPtr); // This call is handled gracefully

    std::cout << "Final value of number: " << number << std::endl;

    return 0;
}