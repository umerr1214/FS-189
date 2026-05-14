#include <iostream>
#include <cctype> // For std::tolower

// Function definition with a syntax error: missing semicolon after return statement
int count_vowels(const char* str) {
    if (str == nullptr) {
        return 0;
    }

    int count = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        char lower_char = std::tolower(static_cast<unsigned char>(str[i]));
        if (lower_char == 'a' || lower_char == 'e' || lower_char == 'i' || lower_char == 'o' || lower_char == 'u') {
            count++;
        }
    }
    return count
} // Missing semicolon here

void run_test(const char* input, int expected, const char* test_name) {
    int result = count_vowels(input);
    std::cout << "Test: " << test_name << " (Input: \"" << (input ? input : "nullptr") << "\")\n";
    std::cout << "Expected: " << expected << ", Got: " << result;
    if (result == expected) {
        std::cout << " - PASSED\n";
    } else {
        std::cout << " - FAILED\n";
    }
    std::cout << "--------------------------------\n";
}

int main() {
    run_test("Hello World", 3, "Basic mixed case string");
    run_test("Programming", 3, "Another mixed case string");
    run_test("AEIOUaeiou", 10, "All vowels, mixed case");
    run_test("Rhythm", 0, "No vowels");
    run_test("", 0, "Empty string");
    run_test("c++", 0, "Non-vowel characters");
    run_test("AaEeIiOoUu", 10, "Pairs of mixed case vowels");
    run_test(nullptr, 0, "Null string");
    return 0;
}