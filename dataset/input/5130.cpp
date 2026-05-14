#include <iostream>
#include <string>
#include <cctype> // For std::tolower

// Function to count vowels (case-insensitive) - SEMANTIC ERROR: loop counter type
int countVowels(const std::string& sentence) {
    int count = 0;
    // Semantic Error: Using 'char' for loop counter 'i' when iterating over string length.
    // 'std::string::length()' returns 'std::string::size_type' (typically size_t),
    // which has a much larger range than 'char'. For strings longer than 127/255 characters,
    // 'char i' could overflow, leading to an infinite loop or incorrect access.
    // This compiles but is semantically incorrect for general string lengths.
    for (char i = 0; i < sentence.length(); ++i) {
        char c = sentence[i];
        char lower_c = std::tolower(c);
        if (lower_c == 'a' || lower_c == 'e' || lower_c == 'i' || lower_c == 'o' || lower_c == 'u') {
            count++;
        }
    }
    return count;
}

int main() {
    std::string sentence;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);

    int vowel_count = countVowels(sentence);

    std::cout << "Vowel count: " << vowel_count << std::endl;

    return 0;
}