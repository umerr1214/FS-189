#include <iostream>

int main() {
    char ch;
    std::cout << "Enter a character: ";
    std::cin >> ch;

    // Check if it's an alphabet using manual range checks
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        // It's an alphabet. Now, determine if it's a vowel using a long and repetitive condition.
        // This approach avoids converting to lowercase first, making the condition verbose.
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            std::cout << ch << " is a vowel." << std::endl;
        } else {
            std::cout << ch << " is a consonant." << std::endl;
        }
    } else {
        // Not an alphabet
        std::cout << ch << " is not an alphabet." << std::endl;
    }

    return 0;
}