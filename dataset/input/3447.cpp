#include <iostream>
#include <vector>   // Using std::vector for dynamic array features, though fixed size is fine.
#include <algorithm> // For std::max, demonstrating good practice.

// Function containing the core logic to be tested.
void solve() {
    const int ARRAY_SIZE = 5;
    std::vector<int> numbers(ARRAY_SIZE); // Using std::vector for better C++ practice

    std::cout << "Enter " << ARRAY_SIZE << " integers for the array:\n";

    // Read user-defined values into the array
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << "Enter number " << i + 1 << ": ";
        std::cin >> numbers[i];
        // Good practice would add input validation here,
        // but for a 'Correct Version' focusing on core logic,
        // we assume valid integer input as per typical problem constraints.
    }

    // Handle edge case for an empty array, though not strictly reachable here
    if (numbers.empty()) {
        std::cout << "The array is empty, no largest element to find.\n";
        return;
    }

    // Find the largest element
    // Initialize largestElement with the first element
    int largestElement = numbers[0];
    // Iterate from the second element
    for (int i = 1; i < ARRAY_SIZE; ++i) {
        // Use std::max for conciseness and clarity
        largestElement = std::max(largestElement, numbers[i]);
    }

    // Print the largest element
    std::cout << "The largest element in the array is: " << largestElement << "\n";
}

// Main function to run the solve() logic.
int main() {
    solve();
    return 0;
}