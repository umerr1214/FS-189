#include <iostream> // For input/output operations (std::cin, std::cout)
#include <cmath>    // Required for the sqrt function, used for prime number optimization
#include <algorithm> // Required for std::swap, used for robust range handling

// Function to check if a number is prime efficiently and robustly
bool isPrime(int num) {
    if (num <= 1) { // Numbers less than or equal to 1 are not prime by definition
        return false;
    }
    if (num == 2) { // 2 is the only even prime number
        return true;
    }
    if (num % 2 == 0) { // All other even numbers are not prime
        return false;
    }

    // Optimization: Check for divisibility only by odd numbers
    // from 3 up to the square root of 'num'.
    // Using `i * i <= num` is preferred over `i <= sqrt(num)` to avoid floating-point inaccuracies
    // and potential performance overhead of `sqrt` in a loop condition.
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return false; // Found a divisor, so it's not prime
        }
    }
    return true; // No divisors found, so it's prime
}

// Renamed from main to solution_main for testing purposes
int solution_main() {
    int start_range, end_range; // Clear and descriptive variable names

    std::cout << "Enter the start of the range: ";
    std::cin >> start_range;
    std::cout << "Enter the end of the range: ";
    std::cin >> end_range;

    // Robustness: Ensure start_range is not greater than end_range.
    // If the user inputs an inverted range, swap them to process correctly.
    if (start_range > end_range) {
        std::swap(start_range, end_range);
    }

    // Robustness: Prime numbers start from 2.
    // If the user inputs a start_range less than 2, adjust it to 2.
    if (start_range < 2) {
        start_range = 2;
    }

    // Clear and informative output message
    // std::cout << "Prime numbers in the range [" << start_range << ", " << end_range << "]:" << std::endl;
    // For automated testing, we'll just print the numbers directly without the header line.

    bool found_any_prime = false;
    for (int current_number = start_range; current_number <= end_range; ++current_number) {
        if (isPrime(current_number)) {
            std::cout << current_number << " ";
            found_any_prime = true;
        }
    }

    // Provide clear feedback if no prime numbers were found in the specified (and adjusted) range.
    if (!found_any_prime) {
        std::cout << "No prime numbers found in the specified range.";
    }
    std::cout << std::endl; // Ensure a newline at the end of output

    return 0;
}