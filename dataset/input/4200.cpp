#include <iostream>
#include <cctype> // For std::tolower

// Function with a semantic error: Improper use of std::tolower with char type.
int count_vowels(const char* str) {
    if (str == nullptr) {
        return 0;
    }

    int count = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        // Semantic error: Passing char directly to std::tolower.
        // If 'char' is signed and 'str[i]' holds a negative value (e.g., for extended ASCII characters),
        // this results in undefined behavior. std::tolower expects an int representable as unsigned char or EOF.
        char lower_char = std::tolower(str[i]); // Should be std::tolower(static_cast<unsigned char>(str[i]));
        if (lower_char == 'a' || lower_char == 'e' || lower_char == 'i' || lower_char == 'o' || lower_char == 'u') {
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