#include <iostream>
#include <string>
#include <algorithm> // For std::swap

int main() {
    std::string s;
    std::cout << "Enter a string: ";
    std::getline(std::cin, s);

    // Semantic error: Off-by-one error in manual reversal logic.
    // When i = 0, `s.length() - i` evaluates to `s.length()`,
    // which is an out-of-bounds index for `std::string` (valid indices are 0 to s.length() - 1).
    // This leads to undefined behavior. The correct index for the last character
    // to swap with s[i] should be `s.length() - 1 - i`.
    for (size_t i = 0; i < s.length() / 2; ++i) {
        std::swap(s[i], s[s.length() - i]);
    }

    std::cout << s << std::endl;

    return 0;
}