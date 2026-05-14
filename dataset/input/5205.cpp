#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

int main() {
    long long sumOfPositives = 0; // Stores the sum of all positive integers entered
    int countOfPositives = 0;     // Stores the count of all positive integers entered
    int inputNumber;              // Variable to store the user's input

    // Prompt the user for input with clear instructions
    std::cout << "Please enter positive integers. Enter -1 to calculate the average and terminate." << std::endl;

    // Loop continuously, reading numbers until the sentinel value (-1) is entered.
    // The loop condition handles both reading input and checking for termination.
    while (std::cin >> inputNumber && inputNumber != -1) {
        // Only process and count numbers that are strictly positive
        if (inputNumber > 0) {
            sumOfPositives += inputNumber; // Add the positive number to the sum
            countOfPositives++;            // Increment the count of positive numbers
        }
    }

    // After the loop, calculate and print the average.
    // Robustly handle the case where no positive integers were entered to prevent division by zero.
    if (countOfPositives > 0) {
        double average = static_cast<double>(sumOfPositives) / countOfPositives;
        std::cout << "The average of the positive integers entered is: ";
        // Format the output to one decimal place for clarity and consistency
        std::cout << std::fixed << std::setprecision(1) << average << std::endl;
    } else {
        // Inform the user if no positive integers were found
        std::cout << "No positive integers were entered." << std::endl;
    }

    return 0; // Indicate successful program execution
}