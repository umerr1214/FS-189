#include <iostream>
#include <string>
#include <cctype> // For std::isspace

// Function with a logical error:
// This implementation counts spaces and adds 1, which is incorrect
// for multiple spaces, leading/trailing spaces, or strings with only spaces.
int countWords(std::string sentence) {
    if (sentence.empty()) {
        return 0; // Correct for empty string
    }

    int count = 1; // Logical error: Assumes at least one word if not empty,
                   // and counts each space as a separator for a new word.
    for (char c : sentence) {
        if (c == ' ') {
            count++;
        }
    }
    return count;
}

int main() {
    std::cout << "Test Case 1: 'Hello world' -> " << countWords("Hello world") << std::endl; // Expected: 2, Actual: 2
    std::cout << "Test Case 2: 'One two three four' -> " << countWords("One two three four") << std::endl; // Expected: 4, Actual: 4
    std::cout << "Test Case 3: '' -> " << countWords("") << std::endl; // Expected: 0, Actual: 0
    std::cout << "Test Case 4: '   leading and trailing   ' -> " << countWords("   leading and trailing   ") << std::endl; // Expected: 3, Actual: 8
    std::cout << "Test Case 5: 'single' -> " << countWords("single") << std::endl; // Expected: 1, Actual: 1
    std::cout << "Test Case 6: '  multiple   spaces  ' -> " << countWords("  multiple   spaces  ") << std::endl; // Expected: 2, Actual: 8
    std::cout << "Test Case 7: '   ' -> " << countWords("   ") << std::endl; // Expected: 0, Actual: 4
    std::cout << "Test Case 8: ' Hello' -> " << countWords(" Hello") << std::endl; // Expected: 1, Actual: 2
    return 0;
}