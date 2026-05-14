#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

int main() {
    int input;
    long long sum = 0;
    int count = 0;
    double average;

    std::cout << "Enter positive integers (enter -1 to terminate): " << std::endl;

    while (true) {
        std::cin >> input;

        if (input == -1) {
            break;
        }

        // Logical Error: The program includes 0 and negative numbers (other than -1)
        // in the sum and count for the average calculation.
        // The question specifies "average of all positive integers".
        sum += input; // This adds all numbers except -1
        count++;      // This counts all numbers except -1
    }

    if (count > 0) {
        average = static_cast<double>(sum) / count;
        std::cout << "Average of all entered numbers (excluding -1): " << std::fixed << std::setprecision(2) << average << std::endl;
    } else {
        std::cout << "No numbers were entered (excluding -1)." << std::endl;
    }

    return 0;
}