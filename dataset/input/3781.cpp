#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip> // For std::fixed and std::setprecision

void solve() {
    std::vector<int> numbers(8);
    long long sum = 0; // Using long long for sum to prevent potential overflow, though not critical for 8 ints.
    const int ARRAY_SIZE = 8;

    std::cout << "Please enter " << ARRAY_SIZE << " integers:" << std::endl;

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << "Enter integer " << i + 1 << ": ";
        std::cin >> numbers[i];
        // ROBUSTNESS ISSUE: No error checking for std::cin's state.
        // If a non-integer is entered, std::cin will go into a fail state.
        // Subsequent reads will fail immediately without reading anything,
        // leaving the remaining elements of 'numbers' uninitialized or at their default
        // value (0 for std::vector elements). The program will then calculate
        // an average based on these potentially incorrect values without proper warning
        // or recovery, leading to incorrect output.
    }

    // Calculate sum from the array, which might contain incorrect values if input failed.
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        sum += numbers[i];
    }

    // This check comes too late; the issue is that input failures were not handled immediately.
    if (std::cin.good() || std::cin.eof()) {
        double average = static_cast<double>(sum) / ARRAY_SIZE;
        std::cout << std::fixed << std::setprecision(1) << "The average of the values is: " << average << std::endl;
    } else {
        std::cout << "An error occurred during input. The calculated average might be incorrect." << std::endl;
        double average = static_cast<double>(sum) / ARRAY_SIZE; // Still print the potentially wrong average.
        std::cout << std::fixed << std::setprecision(1) << "Calculated average (potentially incorrect): " << average << std::endl;
    }
}

int main() {
    solve();
    return 0;
}