#include <iostream>
#include <string>
#include <limits> // For std::numeric_limits

int main() {
    std::string sentence;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);

    int wordCount = 0;
    size_t currentPos = 0;

    // This approach uses repeated string searching operations (find_first_not_of, find),
    // which can be less efficient than a single pass character iteration for very long strings.
    // While correct, it involves more overhead due to multiple function calls and potentially
    // rescanning parts of the string, making it an efficiency issue.
    while (currentPos < sentence.length()) {
        // Skip leading spaces
        size_t wordStart = sentence.find_first_not_of(' ', currentPos);

        if (wordStart == std::string::npos) {
            // No more non-space characters found, all remaining are spaces
            break;
        }

        // Find the end of the word (first space after wordStart)
        size_t wordEnd = sentence.find(' ', wordStart);

        wordCount++;

        if (wordEnd == std::string::npos) {
            // Reached the end of the string after the last word
            break;
        }

        // Move current position past the word and its following space(s)
        currentPos = wordEnd;
    }

    std::cout << "Total number of words: " << wordCount << std::endl;

    return 0;
}