#include <iostream>
#include <iomanip> // For std::fixed, std::setprecision

int main() {
    const int ARRAY_SIZE = 5;
    float numbers[ARRAY_SIZE] = {0.0f}; // Initialize to 0.0f to make behavior predictable on failed input
    float sum = 0.0f;

    std::cout << "Please enter 5 floating-point numbers:" << std::endl;

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << "Enter number " << i + 1 << ": ";
        std::cin >> numbers[i]; // No input validation; cin state is not checked
    }

    // Calculate sum
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        sum += numbers[i];
    }

    float average = sum / ARRAY_SIZE;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "The average of the numbers is: " << average << std::endl;

    return 0;
}