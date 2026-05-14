#include <iostream>
#include <string>
#include <algorithm> // Required for std::reverse

int main() {
    std::string s;
    std::getline(std::cin, s); // Correct input handling

    // Efficiency issue: Creates a full copy of the string and reverses it.
    // This uses O(N) extra space and involves copying operations,
    // whereas a two-pointer approach uses O(1) extra space.
    std::string reversed_s = s;
    std::reverse(reversed_s.begin(), reversed_s.end());

    // Readability: The comparison itself is clear, but the preceding steps
    // are less efficient than necessary.
    if (s == reversed_s) {
        std::cout << "Palindrome" << std::endl;
    } else {
        std::cout << "Not a palindrome" << std::endl;
    }

    return 0;
}