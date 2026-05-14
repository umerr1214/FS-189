#include <iostream>
#include <string>
#include <limits> // Required for numeric_limits
#include <algorithm> // Required for std::count

int main() {
    std::string sentence;
    char char_to_find;
    
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence); // Correctly reads the entire line, including spaces

    std::cout << "Enter the character to count: ";
    std::cin >> char_to_find; // Reads the single character

    // Robustly clear the input buffer to discard the newline character
    // left by std::cin >> char_to_find, preventing issues with future std::getline calls
    // (though not strictly necessary here as there are no further `getline` calls, it's good practice).
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Efficiently count occurrences using the std::count algorithm.
    // This is highly readable, concise, and performs a single linear pass (O(N) complexity).
    long long count = std::count(sentence.begin(), sentence.end(), char_to_find);

    std::cout << "The character '" << char_to_find << "' appears " << count << " times in the sentence." << std::endl;

    return 0;
}