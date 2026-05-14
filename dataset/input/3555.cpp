#include <iostream>

// Function to increment the value pointed to by ptr by 5 and return the new value.
// This is the correct and idiomatic implementation.
int incrementPointerValue(int* ptr) {
    // For a truly robust version, a nullptr check would be added, but per problem
    // statement's implied context, a valid pointer is assumed.
    *ptr += 5;      // Increment the value at the memory location pointed to by ptr
    return *ptr;    // Return the new value
}

int main() {
    int score = 100;
    std::cout << "Initial score: " << score << std::endl; // Expected: 100

    // Demonstrate usage with a positive value
    int newScore = incrementPointerValue(&score);
    std::cout << "Score after first increment: " << score << std::endl;    // Expected: 105
    std::cout << "Returned value from first call: " << newScore << std::endl; // Expected: 105

    int temperature = -5;
    std::cout << "\nInitial temperature: " << temperature << std::endl; // Expected: -5

    // Demonstrate usage with a negative value
    int newTemperature = incrementPointerValue(&temperature);
    std::cout << "Temperature after increment: " << temperature << std::endl; // Expected: 0
    std::cout << "Returned value from second call: " << newTemperature << std::endl; // Expected: 0

    // Demonstrate usage with zero
    int count = 0;
    std::cout << "\nInitial count: " << count << std::endl; // Expected: 0
    int newCount = incrementPointerValue(&count);
    std::cout << "Count after increment: " << count << std::endl; // Expected: 5
    std::cout << "Returned value from third call: " << newCount << std::endl; // Expected: 5

    return 0;
}