#include <iostream>
#include <string>
#include <algorithm> // Not used, demonstrating inefficiency

// Helper function for testing purposes: reverses a string inefficiently.
std::string getReversedString(std::string in_str) {
    std::string rev_str = ""; // Inefficient: repeatedly reallocates memory
    int len = in_str.length(); // Using int for length, might be an issue for very long strings but okay for typical words
    for (int i = 0; i < len; ++i) {
        rev_str = in_str[i] + rev_str; // Prepending characters makes this operation O(N) in a loop, leading to O(N^2) total complexity.
    }
    return rev_str;
}

int main() {
    std::string myWord;
    std::cout << "Enter a word: ";
    std::cin >> myWord;

    std::string resultWord = getReversedString(myWord);
    std::cout << "Reversed word: " << resultWord << std::endl;

    return 0;
}