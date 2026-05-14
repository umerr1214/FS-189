#include <iostream>
#include <string>

int main() {
    std::string sentence;
    char targetChar;
    int count = 0;

    std::cout << "Enter a sentence: " // Syntax Error: Missing semicolon
    std::getline(std::cin, sentence);

    std::cout << "Enter a character to count: ";
    std::cin >> targetChar;

    for (char c : sentence) {
        if (c == targetChar) {
            count++;
        }
    }

    std::cout << "The character '" << targetChar << "' appears " << count << " times." << std::endl;

    return 0;
}