#include <iostream>
#include <string>

// This version has a robustness issue: it does not handle non-integer input.
// If non-integer input is provided, std::cin will fail, the variable 'num'
// might not be updated (or retain its default/previous value), and the program
// will proceed with potentially incorrect data, leading to incorrect output.
// It also leaves std::cin in a failed state.
void solve() {
    int num = 0; // Initialize to 0 to make behavior somewhat predictable on bad input
    std::cout << "Enter an integer: ";
    std::cin >> num;

    // No check for cin.fail() or error handling.
    // If input is "abc", num will likely remain 0, and it will print "Zero".

    if (num > 0) {
        std::cout << "Positive" << std::endl;
    } else if (num < 0) {
        std::cout << "Negative" << std::endl;
    } else {
        std::cout << "Zero" << std::endl;
    }
}