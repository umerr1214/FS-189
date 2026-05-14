#include <iostream>
#include <string>
#include <cctype> // For std::tolower

int main() {
    std::string sentence;
    std::cout << "Enter a sentence: ";
    // Robustness Issue: Using operator>> for std::string reads only up to the first whitespace.
    // It will not read the entire sentence if it contains spaces.
    std::cin >> sentence;

    int vowelCount = 0;
    for (char c : sentence) {
        char lowerC = std::tolower(static_cast<unsigned char>(c)); // Cast for std::tolower safety
        if (lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u') {
            vowelCount++;
        }
    }

    std::cout << "Vowel count: " << vowelCount << std::endl;

    return 0;
}