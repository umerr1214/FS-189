#include <iostream>
#include <vector>
#include <numeric> // Not used for manual sum, but often included for such tasks
#include <iomanip> // For formatting output

int main() {
    const int SIZE = 5;
    float numbers[SIZE];
    float sum = 0.0f; // Using 'f' suffix for float literals

    std::cout << "Enter " << SIZE << " floating-point numbers:" << std::endl;

    for (int i = 0; i < SIZE; ++i) {
        std::cout << "Enter number " << i + 1 << ": ";
        std::cin >> numbers[i];
        sum += numbers[i];
    }

    // Logical error: Dividing by (SIZE - 1) instead of SIZE for the average calculation.
    // This will lead to an incorrect average unless SIZE is 1 (which would be division by zero).
    float average = sum / (SIZE - 1); 

    std::cout << std::fixed << std::setprecision(2); // Format output to 2 decimal places
    std::cout << "The average of the numbers is: " << average << std::endl;

    return 0;
}