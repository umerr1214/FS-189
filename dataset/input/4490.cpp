#include <iostream>
#include <cctype> // Not strictly needed for this verbose approach, but good practice.

int main() {
    char ch;
    std::cout << "Enter a character: ";
    std::cin >> ch;

    // This approach is verbose and repetitive, comparing against both upper and lower case
    // for each vowel explicitly, instead of converting to a single case first.
    // While correct, it's less readable and less efficient than converting to lowercase once.
    if (ch == 'a' || ch == 'A') {
        std::cout << "'" << ch << "' is a vowel." << std::endl;
    } else if (ch == 'e' || ch == 'E') {
        std::cout << "'" << ch << "' is a vowel." << std::endl;
    } else if (ch == 'i' || ch == 'I') {
        std::cout << "'" << ch << "' is a vowel." << std::endl;
    } else if (ch == 'o' || ch == 'O') {
        std::cout << "'" << ch << "' is a vowel." << std::endl;
    } else if (ch == 'u' || ch == 'U') {
        std::cout << "'" << ch << "' is a vowel." << std::endl;
    } else {
        // For non-alphabetic characters, it will correctly classify them as not vowels,
        // and thus fall into the 'consonant' category, which might be acceptable
        // given the problem statement's focus on vowels/consonants.
        std::cout << "'" << ch << "' is a consonant." << std::endl;
    }

    return 0;
}