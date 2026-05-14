#include <iostream>
#include <string>
#include <cctype> // For std::tolower (though not used correctly here)

// Function to count vowels (case-insensitive) - LOGICAL ERROR: only counts lowercase
int countVowels(const std::string& sentence) {
    int count = 0;
    for (char c : sentence) {
        // Logical Error: Does not convert to lowercase before checking.
        // It will only count 'a', 'e', 'i', 'o', 'u' and ignore 'A', 'E', 'I', 'O', 'U'.
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
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