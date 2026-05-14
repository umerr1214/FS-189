#include <iostream>
#include <string>
#include <limits>

int main() {
    std::string sentence;
    char targetChar;
    int count = 0;

    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);

    std::cout << "Enter a character to count: ";
    std::cin >> targetChar;

    // Logical Error: Loop iterates up to sentence.length() - 1, missing the last character
    for (int i = 0; i < sentence.length() - 1; ++i) {
        if (sentence[i] == targetChar) {
            count++;
        }
    }

    std::cout << "The character '" << targetChar << "' appears " << count << " times in the sentence." << std::endl;

    return 0;
}