#include <iostream>
#include <string>
#include <cctype> // Required for isalpha and tolower

std::string determine_char_type(char input_char) {
    if (!std::isalpha(static_cast<unsigned char>(input_char))) {
        return "Not an alphabet";
    }
    char lower_char = std::tolower(static_cast<unsigned char>(input_char));
    if (lower_char == 'a' || lower_char == 'e' || lower_char == 'i' || lower_char == 'o' || lower_char == 'u') {
        return "Vowel";
    } else {
        return "Consonant";
    }
}

int main() {
    char input;
    std::cout << "Enter a character: " // Syntax Error: Missing semicolon
    std::cin >> input;
    std::cout << determine_char_type(input) << std::endl;
    return 0;
}