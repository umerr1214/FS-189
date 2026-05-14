#include <iostream>
#include <string>
#include <algorithm> // Required for std::count

// Function to count words assuming single spaces and no leading/trailing spaces.
// This is the correct, efficient, and readable version for the given constraints.
int countWords(const std::string& sentence) {
    if (sentence.empty()) {
        return 0;
    }
    // Per the problem statement: "words are separated by single spaces and there are no leading/trailing spaces."
    // This means the number of words is simply the number of spaces + 1 for a non-empty string.
    int numSpaces = std::count(sentence.begin(), sentence.end(), ' ');
    return numSpaces + 1;
}

int main() {
    std::cout << "Enter a sentence: ";
    std::string sentence;
    std::getline(std::cin, sentence);

    int numWords = countWords(sentence);
    std::cout << "Number of words: " << numWords << std::endl;

    return 0;
}