#include <iostream>
#include <string>
#include <sstream> // For std::istringstream

// Function definition with a syntax error: missing semicolon
int countWords(std::string sentence)
{
    std::istringstream iss(sentence) // ERROR: Missing semicolon here
    int count = 0;
    std::string word;
    while (iss >> word) {
        count++;
    }
    return count;
}

int main() {
    std::cout << "Test Case 1: 'Hello world' -> " << countWords("Hello world") << std::endl;
    std::cout << "Test Case 2: 'One two three four' -> " << countWords("One two three four") << std::endl;
    std::cout << "Test Case 3: '' -> " << countWords("") << std::endl;
    std::cout << "Test Case 4: '   leading and trailing   ' -> " << countWords("   leading and trailing   ") << std::endl;
    std::cout << "Test Case 5: 'single' -> " << countWords("single") << std::endl;
    std::cout << "Test Case 6: '  multiple   spaces  ' -> " << countWords("  multiple   spaces  ") << std::endl;
    std::cout << "Test Case 7: '   ' -> " << countWords("   ") << std::endl;
    std::cout << "Test Case 8: ' Hello' -> " << countWords(" Hello") << std::endl;
    return 0;
}