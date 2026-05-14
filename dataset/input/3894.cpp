#include <iostream>
#include <cctype> // For tolower, isalpha

int main() {
    char ch_input;
    std::cout << "Enter a character: ";
    std::cin >> ch_input;

    // Semantic Error: `std::tolower` expects an argument of type `int` that is
    // representable as an `unsigned char` or is `EOF`. Passing a `char` directly
    // can lead to undefined behavior if `char` is signed and `ch_input` holds
    // a negative value (e.g., for extended ASCII characters outside the basic source character set).
    char ch_lower = std::tolower(ch_input);

    if (std::isalpha(ch_input)) { // Check original character for alphabetic property
        if (ch_lower == 'a' || ch_lower == 'e' || ch_lower == 'i' || ch_lower == 'o' || ch_lower == 'u') {
            std::cout << "The character is a vowel." << std::endl;
        } else {
            std::cout << "The character is a consonant." << std::endl;
        }
    } else {
        std::cout << "The character is not an alphabet." << std::endl;
    }

    return 0;
}