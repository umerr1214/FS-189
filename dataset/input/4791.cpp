#include <iostream>
#include <vector> // Good practice to include, even if not strictly used for fixed-size arrays
#include <numeric> // Good practice to include for algorithms like std::accumulate (though not used directly here)
#include <iomanip> // For output formatting
#include <limits>  // Required for std::numeric_limits

int main() {
    const int ARRAY_SIZE = 10; // Use a named constant for array size
    int numbers[ARRAY_SIZE];   // Declare array with named constant
    double sum = 0.0;          // Use double for sum to maintain precision
    double average;            // Use double for average

    std::cout << "Please enter " << ARRAY_SIZE << " integers to populate the array:" << std::endl;

    for (int i = 0; i < ARRAY_SIZE; ++i) { // Clear loop variable 'i'
        std::cout << "Enter integer " << i + 1 << ": ";
        // Robust input validation loop: ensures only integers are accepted
        while (!(std::cin >> numbers[i])) {
            std::cout << "Invalid input. Please enter an integer: ";
            std::cin.clear(); // Clear the error flags
            // Discard invalid input up to the next newline character
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // Calculate the sum of all elements
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        sum += numbers[i];
    }
    // Alternative (more C++ idiomatic, but requires <numeric>):
    // sum = std::accumulate(std::begin(numbers), std::end(numbers), 0.0);

    // Calculate the average
    average = sum / ARRAY_SIZE;

    // Print the average with appropriate precision
    std::cout << std::fixed << std::setprecision(2) << "The average of the elements is: " << average << std::endl;

    return 0;
}