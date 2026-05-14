#include <iostream>
#include <cctype>   // For tolower
#include <cstring>  // For strlen (not strictly needed, but common for C-strings)

// Function to count vowels in a C-style string
// Robustness Issue: Does not handle nullptr input for 'str'.
int countVowels(const char* str) {
    // CRITICAL ROBUSTNESS FLAW: No check for str == nullptr.
    // If nullptr is passed, dereferencing *str or str[i] will lead to a crash (segmentation fault).
    int count = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        char c = std::tolower(static_cast<unsigned char>(str[i])); // Convert to lowercase for case-insensitivity
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

int main() {
    char inputString1[] = "Hello World!";
    std::cout << "Input: \"" << inputString1 << "\"" << std::endl;
    std::cout << "Number of vowels: " << countVowels(inputString1) << std::endl;
    std::cout << "---" << std::endl;

    char inputString2[] = "Programming is FUN";
    std::cout << "Input: \"" << inputString2 << "\"" << std::endl;
    std::cout << "Number of vowels: " << countVowels(inputString2) << std::endl;
    std::cout << "---" << std::endl;

    char inputString3[] = "AEIOUaeiou";
    std::cout << "Input: \"" << inputString3 << "\"" << std::endl;
    std::cout << "Number of vowels: " << countVowels(inputString3) << std::endl;
    std::cout << "---" << std::endl;

    char inputString4[] = "Rhythm";
    std::cout << "Input: \"" << inputString4 << "\"" << std::endl;
    std::cout << "Number of vowels: " << countVowels(inputString4) << std::endl;
    std::cout << "---" << std::endl;

    char inputString5[] = ""; // Empty string
    std::cout << "Input: \"" << inputString5 << "\"" << std::endl;
    std::cout << "Number of vowels: " << countVowels(inputString5) << std::endl;
    std::cout << "---" << std::endl;

    // Demonstrating the robustness issue: Passing a nullptr
    std::cout << "Attempting to count vowels in a nullptr string (EXPECTED CRASH/SEGFAULT):" << std::endl;
    const char* nullPtrString = nullptr;
    // The program is expected to crash here if countVowels is called with nullptr
    std::cout << "Calling countVowels with nullptr..." << std::endl;
    countVowels(nullPtrString); // This line will cause a segmentation fault
    std::cout << "If you see this message, the program did not crash as expected, or the test environment handled it." << std::endl;

    return 0; // This line might not be reached if crash occurs
}