#include <iostream>
#include <string>
// Semantic Error: Missing #include <cctype> for std::isalpha and std::tolower.
// This might compile on some systems due to transitive includes from other headers
// (like <iostream> or <string> on some compilers), but it's semantically incorrect
// as it relies on implementation-defined behavior or compiler extensions.

std::string determine_char_type(char input_char) {
    if (!std::isalpha(static_cast<unsigned char>(input_char))) { // isalpha might be implicitly declared or transitively included
        return "Not an alphabet";
    }
    char lower_char = std::tolower(static_cast<unsigned char>(input_char)); // tolower might be implicitly declared or transitively included
    if (lower_char == 'a' || lower_char == 'e' || lower_char == 'i' || lower_char == 'o' || lower_char == 'u') {
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