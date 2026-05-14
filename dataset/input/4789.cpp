#include <iostream>
#include <iomanip> // For output formatting

int main() {
    int numbers[10]; // Declare an array of 10 integers
    double sum = 0.0;

    std::cout << "Please enter 10 integers to populate the array:" << std::endl;

    for (int i = 0; i < 10; ++i) {
        std::cout << "Enter integer " << i + 1 << ": ";
        // Robustness Issue: No error checking for non-integer input.
        // If non-integer input occurs, std::cin will fail, numbers[i] might be uninitialized (Undefined Behavior),
        // and subsequent reads will also fail, leaving other elements uninitialized.
        // The program will proceed with potentially garbage values, leading to incorrect average.
        std::cin >> numbers[i];
    }

    // Calculate the sum of all elements
    for (int i = 0; i < 10; ++i) {
        sum += numbers[i];
    }

    // Calculate the average
    double average = sum / 10.0;

    // Print the average
    std::cout << std::fixed << std::setprecision(2) << "The average of the elements is: " << average << std::endl;

    return 0;
}