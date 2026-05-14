#include <iostream>
#include <array>     // For std::array, a fixed-size container
#include <numeric>   // For std::accumulate, to sum elements efficiently
#include <iomanip>   // For std::fixed and std::setprecision, to format output
#include <limits>    // For std::numeric_limits, used in input error handling

void solve() {
    const int ARRAY_SIZE = 8; // Use a named constant for array size for clarity and maintainability
    std::array<int, ARRAY_SIZE> numbers; // Use std::array for fixed-size array, providing type safety and modern C++ features
    long long sum = 0; // Use long long for sum to prevent potential overflow with large integer inputs

    std::cout << "Please enter " << ARRAY_SIZE << " integers:" << std::endl;

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << "Enter integer " << i + 1 << ": ";
        // Robust input handling: repeatedly prompts until valid integer input is received
        while (!(std::cin >> numbers[i])) {
            std::cout << "Invalid input. Please enter an integer: ";
            std::cin.clear(); // Clear the error flag on std::cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the invalid input from the buffer
        }
    }

    // Calculate sum using std::accumulate from <numeric> for conciseness and efficiency
    // The 0LL ensures that the accumulation starts with a long long, preventing overflow
    // if intermediate sums exceed int's max value.
    sum = std::accumulate(numbers.begin(), numbers.end(), 0LL);

    // Calculate the average, ensuring floating-point division
    double average = static_cast<double>(sum) / ARRAY_SIZE;

    // Print the average, formatted to one decimal place
    std::cout << std::fixed << std::setprecision(1) << "The average of the values is: " << average << std::endl;
}

int main() {
    solve();
    return 0;
}