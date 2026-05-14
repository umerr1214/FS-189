#include <iostream>
#include <string>
#include <limits> // Required for numeric_limits

int main() {
    std::string sentence;
    char char_to_find;
    int count = 0;

    std::cout << "Enter a sentence: ";
    // Robustness Issue: Using std::cin >> sentence; will only read up to the first whitespace.
    // If the user enters "Hello World", only "Hello" will be stored in 'sentence'.
    std::cin >> sentence; 

    std::cout << "Enter the character to count: ";
    std::cin >> char_to_find;

    // Clear any remaining characters in the input buffer, including the newline
    // left by the character input, to prevent issues with future inputs (if any).
    // While this line is good practice, it doesn't mitigate the primary robustness issue
    // of `std::cin >> sentence;` truncating the sentence input.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (char c : sentence) {
        if (c == char_to_find) {
            count++;
        }
    }

    std::cout << "The character '" << char_to_find << "' appears " << count << " times in the sentence." << std::endl;

    return 0;
}