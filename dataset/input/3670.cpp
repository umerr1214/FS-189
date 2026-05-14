#include <iostream>
#include <string>
#include <vector> // Not strictly needed, but common includes

void solve(std::istream& in, std::ostream& out) {
    out << "Enter a sentence: " << std::endl;
    std::string sentence;
    std::getline(in, sentence);

    int wordCount = 0;
    if (sentence.empty()) {
        wordCount = 0;
    } else {
        bool inWord = false;
        for (char c : sentence) {
            if (c == ' ') {
                inWord = false;
            } else if (!inWord) {
                wordCount++;
                inWord = true;
            }
        }
    }
    
    // SYNTAX ERROR: Missing '<<' operator before std::endl
    out << "Number of words: " << wordCount std::endl;
}

int main() {
    solve(std::cin, std::cout);
    return 0;
}