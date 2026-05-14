#include <iostream>
#include <string>
#include <cctype> // Required for isalpha and tolower (even if not fully used for case-insensitivity)

std::string determine_char_type(char input_char) {
    if (!std::isalpha(static_cast<unsigned char>(input_char))) {
        return "Not an alphabet";
    }
    // Logical Error: Does not convert input_char to lowercase before checking.
    // This makes the vowel check case-sensitive, so 'A' will be classified as a consonant.
    if (input_char == 'a' || input_char == 'e' || input_char == 'i' || input_char == 'o' || input_char == 'u') {
        return "Vowel";
    } else {
        return "Consonant";
    }
}

int main() {
    char input;
    std::cout << "Enter a character: ";
    std::cin >> input;
    std::cout << determine_char_type(input) << std::endl;
    return 0;
}