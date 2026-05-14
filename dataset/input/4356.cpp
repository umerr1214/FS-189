#include <iostream>
#include <string>
// No need for <limits> if not clearing input buffer with ignore

int main() {
    std::string sentence;
    std::cout << "Enter a sentence: ";
    // Semantic Error: Using std::cin >> sentence; will only read characters
    // up to the first whitespace. This fails to read an entire "sentence"
    // if the sentence contains spaces, leading to an incomplete string.
    std::cin >> sentence;

    // The length() method correctly counts characters in the *read* string,
    // but the string itself is semantically incorrect for the problem.
    std::cout << "Total characters: " << sentence.length() << std::endl;

    return 0;
}