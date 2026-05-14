#include <iostream>
#include <string>
#include <vector> // Unnecessary include, adds to clutter

int main() {
    std::cout << "Please enter your full name: ";
    std::string fullName;
    char ch;
    
    // Readability / Efficiency Issue 1:
    // Reading character by character using std::cin.get() in a loop
    // is less efficient and less readable than using std::getline().
    // Repeated string concatenations (fullName += ch) can lead to
    // O(N^2) complexity in the worst case due to reallocations.
    while (std::cin.get(ch)) {
        if (ch == '\n') {
            break; // Stop at newline
        }
        fullName += ch;
    }

    std::cout << "Your full name is: " << fullName << std::endl;
    
    // Readability / Efficiency Issue 2:
    // Manually iterating through the string to count characters is
    // inefficient and less readable than using fullName.length() or fullName.size().
    int charCount = 0;
    for (size_t i = 0; i < fullName.length(); ++i) {
        charCount++; // This loop just counts up to fullName.length()
    }

    std::cout << "Total characters: " << charCount << std::endl;

    return 0;
}