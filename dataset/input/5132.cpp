#include <iostream>
#include <string>
#include <algorithm> // For std::transform
#include <cctype>    // For std::tolower

int main() {
    std::string sentence;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);

    // Readability/Efficiency Issue:
    // 1. Converts the entire string to lowercase first, which is an extra pass.
    // 2. Uses a long, repetitive if-else-if chain for vowel checking, which is less readable
    //    and potentially less efficient than a switch statement or a lookup table for many checks.
    //    Though for only 5 vowels, the performance difference is negligible, readability suffers.

    // Efficiency Issue part 1: Extra pass to convert whole string to lowercase
    std::transform(sentence.begin(), sentence.end(), sentence.begin(),
                   [](unsigned char c){ return std::tolower(c); });

    int vowelCount = 0;
    for (char c : sentence) {
        // Readability Issue part 2: Long, repetitive conditional check
        if (c == 'a') {
            vowelCount++;
        } else if (c == 'e') {
            vowelCount++;
        } else if (c == 'i') {
            vowelCount++;
        } else if (c == 'o') {
            vowelCount++;
        } else if (c == 'u') {
            vowelCount++;
        }
    }

    std::cout << "Vowel count: " << vowelCount << std::endl;

    return 0;
}