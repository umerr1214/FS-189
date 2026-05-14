#include <iostream>
#include <string>

// This program demonstrates a robustness issue:
// It uses `std::cin >> stringVar` which only reads a single word,
// failing to capture multi-word strings as expected by the prompt.
// It also does not check `std::cin.fail()` after input operations.
void solve() {
    std::string userString;
    char targetChar;
    int count = 0;

    std::cout << "Enter string: ";
    // Robustness Issue: Using operator>> for string reads only up to the first whitespace.
    // If user enters "hello world", userString will be "hello".
    std::cin >> userString; 

    std::cout << "Enter character: ";
    // If the previous `std::cin >> userString` left characters in the buffer (e.g., " world\n"),
    // this `std::cin >> targetChar` will attempt to read from those remaining characters first.
    // For "hello world\no\n", userString becomes "hello". The buffer still has " world\no\n".
    // targetChar will then read 'w'.
    std::cin >> targetChar; 

    // No error checking for std::cin.fail() which can lead to undefined behavior if input stream fails.

    for (int i = 0; i < userString.length(); ++i) {
        if (userString[i] == targetChar) {
            count++;
        }
    }

    std::cout << "The character '" << targetChar << "' appears " << count << " time";
    if (count != 1) {
        std::cout << "s";
    }
    std::cout << " in \"" << userString << "\"." << std::endl;
}

int main() {
    solve();
    return 0;
}