#include <iostream>
#include <string>
#include <limits> // Required for numeric_limits

int main() {
    std::string sentence;
    char targetChar;
    int count = 0;

    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);

    std::cout << "Enter a character to count: " // Missing semicolon here
    std::cin >> targetChar;

    for (char c : sentence) {
        if (c == targetChar) {
            count++;
        }
    }

    std::cout << "The character '" << targetChar << "' appears " << count << " times in the sentence." << std::endl;

    return 0;
}