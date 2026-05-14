#include <iostream>
#include <iomanip> // For formatting output

int main() {
    const int SIZE = 5;
    float numbers[SIZE]; // Declares an array with valid indices from 0 to SIZE-1
    float sum = 0.0f;

    std::cout << "Enter " << SIZE << " floating-point numbers:" << std::endl;

    // Semantic error: The loop condition `i <= SIZE` causes an out-of-bounds write.
    // For i = SIZE, `numbers[SIZE]` is accessed, which is outside the array's allocated memory.
    // This leads to undefined behavior.
    for (int i = 0; i <= SIZE; ++i) { 
        std::cout << "Enter number " << i + 1 << ": ";
        std::cin >> numbers[i]; // Potential out-of-bounds write when i == SIZE
    }

    // Summing the elements. Even if the out-of-bounds write didn't cause a crash,
    // the data in `numbers` might be corrupted, leading to an incorrect sum.
    for (int i = 0; i < SIZE; ++i) {
        sum += numbers[i];
    }

    float average = sum / SIZE;

    std::cout << std::fixed << std::setprecision(2); // Format output to 2 decimal places
    std::cout << "The average of the numbers is: " << average << std::endl;

    return 0;
}