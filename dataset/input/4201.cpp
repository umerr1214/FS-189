#include <iostream>
#include <cctype> // For tolower
#include <cstring> // For strlen

int count_vowels(const char* str) {
    // Robustness Issue: Does not handle nullptr input.
    // If str is nullptr, strlen(str) or str[i] will cause a crash (segmentation fault).
    int count = 0;
    // The loop condition `i < strlen(str)` is also inefficient as strlen is called in each iteration,
    // but the primary error type for this file is Robustness.
    // Correct way would be to get length once or iterate until '\0'.
    // However, the main point here is the crash on nullptr.
    for (int i = 0; str[i] != '\0'; ++i) { // This loop condition fixes the strlen inefficiency from earlier thought, but the nullptr crash remains.
                                         // Let's revert to original thought to ensure a crash if str is nullptr and strlen is used.
                                         // If str is nullptr, str[i] will cause a crash. strlen(str) will also cause a crash.
                                         // To specifically highlight `strlen` as the point of failure for `nullptr`, I'll use it.
        char ch = std::tolower(static_cast<unsigned char>(str[i]));
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    return count;
}

// The main function (driver) will be provided by the testing framework.
// It will avoid calling count_vowels with nullptr to prevent a crash during automated evaluation,
// but the error description will highlight this robustness issue.
int main() {
    // Example usage (not the full driver, which is in JSON)
    // This is just to make the file a complete compilable unit.
    std::cout << "Vowels in 'Programming': " << count_vowels("Programming") << std::endl; // Expected: 4
    std::cout << "Vowels in 'AEIOU': " << count_vowels("AEIOU") << std::endl; // Expected: 5
    // count_vowels(nullptr); // This would crash the program due to robustness issue.
    return 0;
}