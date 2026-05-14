#include <iostream>

void incrementValue(int* ptr) {
    // Readability/Efficiency issue: Uses an unnecessary temporary variable
    // for a simple increment, making the code less concise and slightly less efficient.
    int temporaryValue = *ptr;
    temporaryValue = temporaryValue + 1;
    *ptr = temporaryValue;
}

int main() {
    int myValue = 5;
    std::cout << "Initial value: " << myValue << std::endl;
    incrementValue(&myValue);
    std::cout << "After increment: " << myValue << std::endl;

    int anotherValue = 99;
    std::cout << "Initial value: " << anotherValue << std::endl;
    incrementValue(&anotherValue);
    std::cout << "After increment: " << anotherValue << std::endl;

    return 0;
}