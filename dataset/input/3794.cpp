#include <iostream>
#include <string>
#include <limits> // Required for numeric_limits
#include <algorithm> // Not strictly needed for this inefficient approach, but often included

int main() {
    std::string s; // Poor variable name: 's' for sentence
    char c;       // Poor variable name: 'c' for character
    int res = 0;  // Poor variable name: 'res' for result/count

    std::cout << "Enter a sentence: ";
    std::getline(std::cin, s); // Correctly reads the entire line

    std::cout << "Enter the character to count: ";
    std::cin >> c; // Reads the character

    // Clear the input buffer after reading char, for robustness (good practice)
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Efficiency Issue: This counting method is highly inefficient.
    // It creates a copy of the string and repeatedly searches for the character,
    // then modifies (erases) the string, leading to O(N*M) or worse complexity
    // where N is string length and M is number of occurrences, due to string copying/shifting.
    std::string temp_s = s;
    while (true) {
        size_t p = temp_s.find(c); // Find the first occurrence
        if (p == std::string::npos) {
            break; // No more occurrences found
        }
        res++; // Increment count
        temp_s.erase(p, 1); // Erase the found character, shifting the rest of the string
    }

    std::cout << "The character '" << c << "' appears " << res << " times in the sentence." << std::endl;

    return 0;
}