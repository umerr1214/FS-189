#include <iostream>
#include <string>
#include <algorithm> // For std::count
#include <limits>    // For std::numeric_limits

int main() {
    std::string sentence;
    std::cout << "Enter a sentence: ";
    // Use std::getline to read the entire line, including spaces
    std::getline(std::cin, sentence);

    // This approach counts spaces and adds one.
    // It is not robust for empty strings, strings with only spaces,
    // or strings with leading/trailing spaces.
    int wordCount = 0;
    if (!sentence.empty()) {
        wordCount = std::count(sentence.begin(), sentence.end(), ' ') + 1;
    }
    // If the sentence is empty, wordCount remains 0, but if it has spaces,
    // it will incorrectly count for empty strings (e.g., "" -> 1)
    // or strings with only spaces (e.g., "   " -> 3+1=4 words).
    // The conditional `if (!sentence.empty())` prevents adding 1 for an empty string,
    // but still fails for "   " (counts 3 spaces, adds 1, gets 4 words).

    std::cout << "Total number of words: " << wordCount << std::endl;

    return 0;
}