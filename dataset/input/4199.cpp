#include <iostream>
#include <cctype> // For std::tolower, but not used correctly

// Function with a logical error: Fails to convert characters to lowercase
// before checking for vowels, making it case-sensitive instead of case-insensitive.
int count_vowels(const char* str) {
    if (str == nullptr) {
        return 0;
    }

    int count = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        // Logical error: The function is supposed to be case-insensitive,
        // but it only checks for lowercase vowels directly. It does not
        // convert the character to lowercase before comparison.
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            count++;
        }
    }
    return count;
}

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
    run_test("Hello World", 3, "Basic mixed case string"); // Expected: 3, Actual: 2 (O in World missed)
    run_test("Programming", 3, "Another mixed case string"); // Expected: 3, Actual: 3
    run_test("AEIOUaeiou", 10, "All vowels, mixed case"); // Expected: 10, Actual: 5 (uppercase missed)
    run_test("Rhythm", 0, "No vowels"); // Expected: 0, Actual: 0
    run_test("", 0, "Empty string"); // Expected: 0, Actual: 0
    run_test("c++", 0, "Non-vowel characters"); // Expected: 0, Actual: 0
    run_test("AaEeIiOoUu", 10, "Pairs of mixed case vowels"); // Expected: 10, Actual: 5 (uppercase missed)
    run_test(nullptr, 0, "Null string");
    return 0;
}