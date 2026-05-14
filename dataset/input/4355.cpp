#include <iostream>
#include <string>
#include <limits> // Required for numeric_limits

int main() {
    std::string sentence;
    std::cout << "Enter a sentence: ";
    // Clear any potential leftover newline character from previous inputs
    // (though not strictly necessary for a fresh cin)
    if (std::cin.peek() == '\n') {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::getline(std::cin, sentence);

    int char_count = 0;
    for (char c : sentence) {
        // Logical Error: This condition explicitly excludes spaces from the count.
        // The question asks to count ALL characters, including spaces.
        if (c != ' ') {
            char_count++;
        }
    }

    std::cout << "Total characters: " << char_count << std::endl;

    return 0;
}