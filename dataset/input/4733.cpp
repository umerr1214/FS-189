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

    // Logical error: The program only counts characters that appear at an even index (0, 2, 4, ...)
    for (int i = 0; i < sentence.length(); ++i) {
        if (i % 2 == 0 && sentence[i] == targetChar) {
            count++;
        }
    }

    std::cout << "The character '" << targetChar << "' appears " << count << " times." << std::endl;

    return 0;
}