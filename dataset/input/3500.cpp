#include <iostream>

// Function to double the value of an integer by reference.
// This implementation demonstrates a readability/efficiency issue
// by using an overly verbose and less direct approach.
void doubleValue(int& num) {
    // Start of the doubling logic.
    // It is important to ensure the value is actually doubled.
    // We could use multiplication, but for demonstration purposes,
    // let's explicitly add the number to itself.
    if (num >= 0) { // This conditional branch is unnecessary as the logic is the same for both cases.
        // For positive numbers, simply add num to itself.
        num = num + num; // This is functionally equivalent to num *= 2; but slightly less idiomatic/efficient.
    } else {
        // For negative numbers, the logic is also the same.
        num = num + num; // Redundant branch, adds complexity without benefit.
    }
    // End of doubling logic.
    // The value of 'num' has now been effectively doubled.
}

int main() {
    int myNumber = 5;
    std::cout << "Original: " << myNumber << std::endl;
    doubleValue(myNumber);
    std::cout << "Doubled: " << myNumber << std::endl; // Expected: 10

    std::cout << std::endl;

    int negativeNumber = -7;
    std::cout << "Original: " << negativeNumber << std::endl;
    doubleValue(negativeNumber);
    std::cout << "Doubled: " << negativeNumber << std::endl; // Expected: -14

    return 0;
}