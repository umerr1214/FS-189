#include <iostream>
#include <string>

void solve() {
    std::string fullName;
    std::cout << "Please enter your full name: ";
    std::getline(std::cin, fullName);

    std::cout << "Full Name: " << fullName << std::endl // Syntax Error: Missing semicolon here
    std::cout << "Number of characters: " << fullName.length() << std::endl;
}

int main() {
    solve();
    return 0;
}