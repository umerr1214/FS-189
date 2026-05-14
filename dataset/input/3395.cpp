#include <iostream>
#include <string>
#include <algorithm> // Required for std::count

int main() {
    std::string sentence;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);

    // Logical Error: This code counts the number of spaces, not the number of words.
    // For a sentence with N words (separated by single spaces), there will be N-1 spaces.
    // Thus, this logic will consistently return (N-1) for N words.
    // It correctly returns 0 for an empty string, but is incorrect for any non-empty sentence.
    int wordCount = std::count(sentence.begin(), sentence.end(), ' ');

    std::cout << "Number of words: " << wordCount << std::endl;

    return 0;
}