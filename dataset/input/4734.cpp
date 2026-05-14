#include <iostream>
#include <string>

int main() {
    std::string sentence;
    char targetChar;
    int count = 0;

    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);

    std::cout << "Enter a character to count: ";
    std::cin >> targetChar;

    // Semantic error: The loop condition `i < sentence.length() - 1` causes an off-by-one error,
    // skipping the last character of the sentence.
    for (int i = 0; i < sentence.length() - 1; ++i) { // Should be i < sentence.length()
        if (sentence[i] == targetChar) {
            count++;
        }
    }

    std::cout << "The character '" << targetChar << "' appears " << count << " times." << std::endl;

    return 0;
}