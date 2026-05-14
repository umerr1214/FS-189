#include <iostream>

/**
 * @brief Doubles the value of an integer passed by reference.
 *
 * This function takes an integer variable by reference and modifies its
 * value in place by multiplying it by 2. This is an efficient and
 * straightforward implementation.
 *
 * @param num A reference to an integer whose value is to be doubled.
 */
void doubleValue(int& num) {
    num *= 2; // Doubles the value of num using the multiplication assignment operator.
}

int main() {
    // --- Test Case 1: Positive integer ---
    int myInteger = 15;
    std::cout << "Original: " << myInteger << std::endl;

    doubleValue(myInteger); // Call the function to double the value

    std::cout << "Doubled: " << myInteger << std::endl; // Expected: 30

    std::cout << std::endl;

    // --- Test Case 2: Negative integer ---
    int anotherInteger = -100;
    std::cout << "Original: " << anotherInteger << std::endl;

    doubleValue(anotherInteger); // Call the function again
    
    std::cout << "Doubled: " << anotherInteger << std::endl; // Expected: -200

    return 0;
}