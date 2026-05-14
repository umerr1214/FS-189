#include <iostream>
#include <string>
#include <algorithm> // Not strictly needed for this robust version's logic, but common for string tasks

// Function containing the program's logic, designed to exhibit a robustness issue
void execute_program_logic() {
    char charToFind;
    std::cout << "Enter a character to count: ";
    std::cin >> charToFind; // Reads the character, but leaves the newline character in the input buffer.

    std::string sentence;
    std::cout << "Enter a sentence: ";
    // This getline call immediately reads the leftover newline from the previous std::cin >> charToFind,
    // resulting in an empty string for 'sentence' if the user pressed Enter after the character.
    std::getline(std::cin, sentence);

    int count = 0;
    // Simple loop to count occurrences
    for (char c : sentence) {
        if (c == charToFind) {
            count++;
        }
    }

    std::cout << "The character '" << charToFind << "' appears " << count << " times." << std::endl;
}

int main() {
    execute_program_logic();
    return 0;
}