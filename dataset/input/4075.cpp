#include <iostream>

// Renamed main to user_main for testing purposes
int user_main() {
    int height;
    // Input is provided by the test driver, no prompt needed.
    std::cin >> height;

    // Robustness Issue: No explicit validation for non-positive height.
    // The loops implicitly handle height <= 0 by not executing,
    // which results in correct empty output as per test cases,
    // but a robust program would explicitly validate and inform the user.
    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    return 0;
}