#include <iostream>
#include <iomanip> // For std::fixed, std::setprecision
#include <limits>  // For std::numeric_limits

int main() {
    const int ARRAY_SIZE = 5; // Use a named constant for array size
    float numbers[ARRAY_SIZE];
    double sum = 0.0; // Use double for sum to maintain precision during accumulation
    double average = 0.0;

    std::cout << "Welcome! This program calculates the average of " << ARRAY_SIZE << " floating-point numbers." << std::endl;
    std::cout << "Please enter " << ARRAY_SIZE << " numbers:" << std::endl;

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << "Enter number " << i + 1 << ": ";
        // Robust input validation loop
        while (!(std::cin >> numbers[i])) {
            std::cout << "Invalid input. Please enter a valid floating-point number: ";
            std::cin.clear(); // Clear the error flags on std::cin
            // Ignore the rest of the invalid line to prevent infinite loops
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // Calculate sum using a range-based for loop for modern C++ style and readability
    for (float num : numbers) {
        sum += num;
    }

    // Calculate average, including a defensive check for ARRAY_SIZE
    if (ARRAY_SIZE > 0) {
        average = sum / ARRAY_SIZE;
    } else {
        // This branch is technically unreachable for ARRAY_SIZE = 5,
        // but good practice for a more general average function.
        average = 0.0; 
    }

    std::cout << std::fixed << std::setprecision(2); // Format output to 2 decimal places
    std::cout << "The average of the " << ARRAY_SIZE << " numbers is: " << average << std::endl;

    return 0;
}