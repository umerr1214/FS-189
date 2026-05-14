#include <iostream>
#include <string>
#include <sstream> // For std::istringstream

// Function definition with a semantic error:
// The function is supposed to return the *number* of words (int),
// but its return type is `bool`. This will implicitly convert the word count
// to a boolean value (0 -> false, non-0 -> true).
bool countWords(std::string sentence) { // Semantic error: Return type should be int, not bool
    std::istringstream iss(sentence);
    int count = 0;
    std::string word;
    while (iss >> word) {
        count++;
    }
    return count; // Implicit conversion from int to bool (0 -> false, any other int -> true)
}

int main() {
    std::cout << "Test Case 1: 'Hello world' -> " << countWords("Hello world") << std::endl; // Expected: 2, Actual: 1 (true)
    std::cout << "Test Case 2: 'One two three four' -> " << countWords("One two three four") << std::endl; // Expected: 4, Actual: 1 (true)
    std::cout << "Test Case 3: '' -> " << countWords("") << std::endl; // Expected: 0, Actual: 0 (false)
    std::cout << "Test Case 4: '   leading and trailing   ' -> " << countWords("   leading and trailing   ") << std::endl; // Expected: 3, Actual: 1 (true)
    std::cout << "Test Case 5: 'single' -> " << countWords("single") << std::endl; // Expected: 1, Actual: 1 (true)
    std::cout << "Test Case 6: '  multiple   spaces  ' -> " << countWords("  multiple   spaces  ") << std::endl; // Expected: 2, Actual: 1 (true)
    std::cout << "Test Case 7: '   ' -> " << countWords("   ") << std::endl; // Expected: 0, Actual: 0 (false)
    std::cout << "Test Case 8: ' Hello' -> " << countWords(" Hello") << std::endl; // Expected: 1, Actual: 1 (true)
    return 0;
}