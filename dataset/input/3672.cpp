#include <iostream>
#include <string>
#include <sstream>

void solve(std::istream& in, std::ostream& out) {
    out << "Enter a sentence: " << std::endl;
    std::string sentence;
    
    // SEMANTIC ERROR: The question explicitly states to use `std::getline`
    // to accept a sentence. Using `std::cin >> sentence;` only reads
    // the first word up to the first whitespace, failing to accept the full sentence.
    in >> sentence; 

    int wordCount = 0;
    if (sentence.empty()) {
        wordCount = 0;
    } else {
        // The word counting logic here is correct for a single word,
        // but the input reading itself is flawed according to the prompt.
        wordCount = 1; // If sentence is not empty and only contains one word (due to `in >> sentence`)
    }
    
    out << "Number of words: " << wordCount << std::endl;
}

int main() {
    solve(std::cin, std::cout);
    return 0;
}