#include <iostream>

int main() {
    int number;
    long long sumOfPositives = 0; // Use long long to prevent potential integer overflow for large sums

    std::cout << "Enter integers. The program will stop when a negative number is entered." << std::endl;
    std::cout << "Only positive numbers will be summed." << std::endl;

    do {
        std::cout << "Please enter an integer: ";
        std::cin >> number;

        // In a robust program, one would check for std::cin.fail() here.
        // For this 'Correct Version' context, we assume valid integer input as per problem scope,
        // with robustness issues handled in a separate category.

        if (number > 0) {
            sumOfPositives += number;
        }
    } while (number >= 0);

    std::cout << "The sum of all positive numbers entered is: " << sumOfPositives << std::endl;

    return 0;
}