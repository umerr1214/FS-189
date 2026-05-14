#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Required for std::reverse

// Function with readability/efficiency issue:
// It creates a reversed copy of the string and then compares,
// which is less efficient for large strings than a two-pointer approach
// due to extra memory allocation and copying.
bool is_palindrome(const std::string& s) {
    std::string reversed_s = s; // Creates a copy of the string
    std::reverse(reversed_s.begin(), reversed_s.end()); // Reverses the copy
    return s == reversed_s; // Compares the original with the reversed copy
}

void run_test(const std::string& input, bool expected, int& passed_count, int& total_count) {
    total_count++;
    bool result = is_palindrome(input);
    std::cout << "Input: \"" << input << "\", Expected: " << (expected ? "true" : "false")
              << ", Got: " << (result ? "true" : "false");
    if (result == expected) {
        std::cout << " [PASSED]\n";
        passed_count++;
    } else {
        std::cout << " [FAILED]\n";
    }
}

int main() {
    int passed_count = 0;
    int total_count = 0;

    std::cout << "Testing is_palindrome function (Readability/Efficiency Issue: String copy and reverse)\n";

    run_test("", true, passed_count, total_count);
    run_test("a", true, passed_count, total_count);
    run_test("racecar", true, passed_count, total_count);
    run_test("hello", false, passed_count, total_count);
    run_test("madam", true, passed_count, total_count);
    run_test("A", true, passed_count, total_count);
    run_test("Racecar", false, passed_count, total_count); // Case-sensitive
    run_test("level", true, passed_count, total_count);
    run_test("algorithm", false, passed_count, total_count);
    run_test("abba", true, passed_count, total_count);
    run_test("abcba", true, passed_count, total_count);
    run_test("ab", false, passed_count, total_count);
    run_test("aa", true, passed_count, total_count);
    run_test(" ", true, passed_count, total_count); // Single space
    run_test("!@!", true, passed_count, total_count);
    run_test("!@#", false, passed_count, total_count);
    run_test("Able was I ere I saw Elba", false, passed_count, total_count); // With spaces, case sensitive

    std::cout << "\n--- Test Summary ---\n";
    std::cout << "Passed: " << passed_count << " / " << total_count << std::endl;

    return 0;
}