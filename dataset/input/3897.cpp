#include <iostream>
#include <cctype> // Required for std::isalpha and std::tolower

int main() {
    char ch;
    std::cout << "Enter a character: ";
    std::cin >> ch;

    // Robustly check for input stream failure (e.g., EOF, invalid input)
    if (std::cin.fail()) {
        std::cerr << "Error: Failed to read input or end of input reached." << std::endl;
        return 1; // Indicate an error exit status
    }

    if (std::isalpha(ch)) { // Check if it's an alphabet (case-insensitive)
        char lower_ch = std::tolower(ch); // Convert to lowercase for consistent vowel check
        if (lower_ch == 'a' || lower_ch == 'e' || lower_ch == 'i' || lower_ch == 'o' || lower_ch == 'u') {
            std::cout << ch << " is a vowel." << std::endl;
        } else {
            std::cout << ch << " is a consonant." << std::endl;
        }
    } else {
        // If not an alphabet, display the appropriate message
        std::cout << ch << " is not an alphabet." << std::endl;
    }

    return 0;
}