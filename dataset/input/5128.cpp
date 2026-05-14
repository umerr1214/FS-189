#include <iostream>
#include <string>
#include <cctype> // For std::tolower

// Function to count vowels (case-insensitive)
int countVowels(const std::string& sentence) {
    int count = 0;
    for (char c : sentence) {
        char lower_c = std::tolower(c);
        if (lower_c == 'a' || lower_c == 'e' || lower_c == 'i' || lower_c == 'o' || lower_c == 'u') {
            count++;
        }
    }
    return count;
}

int main() {
    std::string sentence;
    std::cout << "Enter a sentence: " // Missing semicolon here
    std::getline(std::cin, sentence);

    int vowel_count = countVowels(sentence);

    std::cout << "Vowel count: " << vowel_count << std::endl;

    return 0;
}