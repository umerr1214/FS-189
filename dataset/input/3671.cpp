#include <iostream>
#include <string>
#include <sstream> // Included for consistency, though not used in this specific word counting logic

void solve(std::istream& in, std::ostream& out) {
    out << "Enter a sentence: " << std::endl;
    std::string sentence;
    std::getline(in, sentence);

    // LOGICAL ERROR: This logic counts the number of spaces and adds 1.
    // It fails for an empty string (should be 0 words, outputs 1)
    // and for strings consisting only of spaces (e.g., "   ", should be 0 words, outputs 4).
    // It works correctly for non-empty strings with words separated by single spaces.
    int spaceCount = 0;
    for (char c : sentence) {
        if (c == ' ') {
            spaceCount++;
        }
    }
    
    // If the string is empty or contains only spaces, this will incorrectly yield 1 or more words.
    // A correct solution would handle empty strings separately or use a state machine.
    int wordCount = spaceCount + 1;

    out << "Number of words: " << wordCount << std::endl;
}

int main() {
    solve(std::cin, std::cout);
    return 0;
}