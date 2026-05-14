#include <iostream>
#include <string>
#include <vector> // Not strictly necessary for this solution, but sometimes included for string manipulation patterns

// Function to count words assuming single spaces and no leading/trailing spaces.
// This version has an efficiency/readability issue due to using repeated string searching
// instead of a single pass or a more direct counting mechanism like std::count.
int countWords(const std::string& sentence) {
    if (sentence.empty()) {
        return 0;
    }

    int wordCount = 0;
    size_t currentPos = 0;
    
    // Repeatedly find spaces to count them
    size_t spacePos = sentence.find(' ', currentPos);
    while (spacePos != std::string::npos) {
        wordCount++; // Each space separates two words
        currentPos = spacePos + 1;
        spacePos = sentence.find(' ', currentPos);
    }

    // For a non-empty sentence, the number of words is (number of spaces) + 1.
    // This handles the last word and the case of a single-word sentence.
    return wordCount + 1;
}

int main() {
    std::cout << "Enter a sentence: ";
    std::string sentence;
    std::getline(std::cin, sentence);

    int numWords = countWords(sentence);
    std::cout << "Number of words: " << numWords << std::endl;

    return 0;
}