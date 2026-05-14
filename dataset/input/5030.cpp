#include <iostream>
#include <string>
#include <algorithm> // Required for std::reverse

// This program demonstrates readability and efficiency issues.
// - Efficiency: It creates a full reversed copy of the string, which uses extra memory
//   and performs an unnecessary copy operation compared to a two-pointer approach.
// - Readability: Uses less descriptive variable names (s, rs) and lacks modularity
//   (no separate function for palindrome check).

int main() {
    std::cout << "Enter a string: ";
    std::string s; // Less descriptive variable name
    std::getline(std::cin, s); // Correctly reads the entire line

    if (s.empty()) {
        std::cout << "true" << std::endl;
        return 0;
    }

    std::string rs = s; // Creates a copy of the string
    std::reverse(rs.begin(), rs.end()); // Reverses the copy

    // The comparison itself is fine, but the setup for it is less efficient
    if (s == rs) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return 0;
}