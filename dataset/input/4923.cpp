#include <iostream>
#include <limits> // Required for numeric_limits

int main() {
    // Define constants for clarity and maintainability
    const long long SECONDS_PER_MINUTE = 60;
    const long long SECONDS_PER_HOUR = 60 * SECONDS_PER_MINUTE;

    long long totalSecondsInput;

    std::cout << "Enter total number of seconds: ";
    std::cin >> totalSecondsInput;

    // Input validation: Check for non-numeric input or negative values
    if (std::cin.fail() || totalSecondsInput < 0) {
        std::cerr << "Invalid input: Please enter a non-negative integer for seconds." << std::endl;
        // Clear error flags and ignore remaining input for robustness in interactive settings,
        // though for a single-shot program, exiting is sufficient.
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1; // Indicate an error
    }

    // Perform the conversion using integer arithmetic
    long long hours = totalSecondsInput / SECONDS_PER_HOUR;
    long long remainingAfterHours = totalSecondsInput % SECONDS_PER_HOUR;
    long long minutes = remainingAfterHours / SECONDS_PER_MINUTE;
    long long remainingSeconds = remainingAfterHours % SECONDS_PER_MINUTE;

    // Print the result in the specified format
    std::cout << hours << "h " << minutes << "m " << remainingSeconds << "s" << std::endl;

    return 0; // Indicate successful execution
}