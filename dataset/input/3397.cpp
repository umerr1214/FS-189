#include <iostream>
#include <string>
#include <vector> // Included for completeness, not strictly used by countWords logic here

// Function to count words, exhibiting a robustness issue
// It works under the strict assumptions but fails for common deviations.
// Specifically, it counts spaces and adds 1, which fails for multiple spaces
// between words, leading/trailing spaces.
int countWords(const std::string& sentence) {
    if (sentence.empty()) {
        return 0; // Correctly handles empty string
    }

    int wordCount = 1; // Assume at least one word if the string is not empty
    for (char c : sentence) {
        if (c == ' ') {
            wordCount++; // Increments for every space encountered
        }
    }
    return wordCount;
}

int main() {
    std::string sentence;
    std::getline(std::cin, sentence);
    std::cout << countWords(sentence) << std::endl;
    return 0;
}