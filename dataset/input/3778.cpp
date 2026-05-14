#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate, though we'll sum manually
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    const int SIZE = 8;
    int numbers[SIZE];
    long long sum = 0; // Use long long for sum to prevent potential overflow

    std::cout << "Enter " << SIZE << " integers:" << std::endl;

    // Syntax Error: Missing semicolon in the for loop header
    for (int i = 0; i < SIZE i++) { // ERROR: 'i++' expects a semicolon before it
        std::cin >> numbers[i];
        sum += numbers[i];
    }

    // This part of the code would not be reached due to the syntax error
    // but is included for logical consistency with the question.
    double average = static_cast<double>(sum) / SIZE;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "The average of the numbers is: " << average << std::endl;

    return 0;
}