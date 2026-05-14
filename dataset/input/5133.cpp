#include <iostream>
#include <string>
#include <cctype> // For std::tolower

int main() {
    std::string sentence;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence); // Correctly reads the entire line

    int vowelCount = 0;
    for (char c : sentence) {
        // Convert character to lowercase once for case-insensitive comparison
        char lowerC = std::tolower(static_cast<unsigned char>(c)); // Use static_cast for safety with std::tolower

        // Efficient and readable check for vowels using a switch statement
        switch (lowerC) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vowelCount++;
                break;
            default:
                // Not a vowel, do nothing
                break;
        }
    }

    std::cout << "Vowel count: " << vowelCount << std::endl;

    return 0;
}