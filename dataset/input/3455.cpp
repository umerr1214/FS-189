#include <iostream>
#include <string>
#include <algorithm> // Included but not used for reversal

int main() {
    std::string word;
    std::cout << "Enter a word: ";
    std::cin >> word;
    // Logical Error: The program reads the word but fails to reverse it.
    // It then prints the original word, not the reversed one.
    // The std::reverse function from <algorithm> is available but not called.
    std::cout << "Reversed word: " << word << std::endl; // Prints the original word
    return 0;
}