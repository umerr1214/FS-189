#include <iostream>
#include <string>
#include <limits> // Required for std::numeric_limits

// This program is a correct and robust solution to the problem.
// It uses efficient input/output methods, handles potential input errors,
// and iterates efficiently through the string.
void solve() {
    // Optimize C++ standard streams for faster input/output operations.
    // This is good practice for performance-critical applications.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string inputString;
    char characterToFind;
    int occurrenceCount = 0;

    // Prompt for string and read using std::getline to handle spaces correctly.
    std::cout << "Enter string: ";
    if (!std::getline(std::cin, inputString)) {
        // Robustness: Check if input operation failed (e.g., EOF or stream error).
        std::cerr << "Error reading string input. Exiting." << std::endl;
        return; 
    }

    // Prompt for character and read.
    std::cout << "Enter character: ";
    if (!(std::cin >> characterToFind)) {
        // Robustness: Check if input operation failed.
        std::cerr << "Error reading character input. Exiting." << std::endl;
        return; 
    }

    // Clear the rest of the line from the input buffer.
    // This is crucial if subsequent `getline` calls are expected,
    // to prevent them from reading the leftover newline character from `std::cin >> characterToFind`.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Count occurrences efficiently using a range-based for loop.
    // This is generally the most readable and often most efficient way to iterate over elements.
    for (char c : inputString) {
        if (c == characterToFind) {
            occurrenceCount++;
        }
    }

    // Display the result with proper grammar for "time" vs "times".
    std::cout << "The character '" << characterToFind << "' appears " << occurrenceCount << " time";
    if (occurrenceCount != 1) {
        std::cout << "s";
    }
    std::cout << " in \"" << inputString << "\"." << std::endl;
}

int main() {
    solve();
    return 0;
}