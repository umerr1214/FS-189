#include <iostream>
#include <string>
#include <algorithm> // Required for std::count
#include <limits>    // Required for std::numeric_limits

// Function containing the correct and efficient program logic
void execute_program_logic() {
    std::string sentence;
    char charToFind;

    std::cout << "Enter a sentence: ";
    // Read the entire line for the sentence, handles spaces correctly.
    std::getline(std::cin, sentence);

    std::cout << "Enter a character to count: ";
    // Read a single character.
    std::cin >> charToFind;

    // Crucial for robustness: Clear the input buffer to discard the leftover newline character
    // from `std::cin >> charToFind`. This prevents it from affecting any subsequent `std::getline`
    // calls, ensuring correct input behavior in a larger program or if inputs were chained.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Efficiently count character occurrences using the standard library algorithm std::count.
    // This is concise, readable, and generally optimized.
    int count = std::count(sentence.begin(), sentence.end(), charToFind);

    std::cout << "The character '" << charToFind << "' appears " << count << " times." << std::endl;
}

int main() {
    execute_program_logic();
    return 0;
}