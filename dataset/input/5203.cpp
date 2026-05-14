#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    long long sum = 0;
    int count = 0;
    int number;

    std::cout << "Enter positive integers (enter -1 to terminate):" << std::endl;

    // Loop to continuously read numbers until -1 is entered
    while (std::cin >> number && number != -1) {
        // Only consider positive integers for sum and count
        if (number > 0) {
            sum += number;
            count++;
        }
    }

    // Robustness Issue: This code does NOT check if 'count' is zero before performing division.
    // If no positive integers were entered (e.g., user immediately enters -1),
    // 'count' will be 0, leading to a division-by-zero runtime error.
    double average = static_cast<double>(sum) / count;

    std::cout << "Average of positive integers: ";
    std::cout << std::fixed << std::setprecision(1) << average << std::endl;

    return 0;
}