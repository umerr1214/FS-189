#include <iostream>
#include <string>

void solve() {
    std::string fullName;
    std::cout << "Please enter your full name: ";
    std::getline(std::cin, fullName);

    std::cout << "Full Name: " << fullName << std::endl;
    // Semantic Error: Using sizeof(std::string) instead of string::length() or string::size()
    // sizeof(fullName) returns the size in bytes of the std::string object itself (e.g., 24 or 32 bytes),
    // not the number of characters in the string it holds.
    std::cout << "Number of characters: " << sizeof(fullName) << std::endl;
}

int main() {
    solve();
    return 0;
}