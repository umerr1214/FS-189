#include <iostream>

int main() {
    long long totalSeconds;

    std::cout << "Enter total number of seconds: ";
    std::cin >> totalSeconds;

    // Robustness Issue: No input validation for negative numbers or non-numeric input.
    // If totalSeconds is negative, C++ integer division/modulo rules apply,
    // potentially leading to negative minutes/seconds, which is an incorrect
    // interpretation for "total number of seconds".
    // If input is non-numeric, std::cin will fail, totalSeconds might remain 0
    // (if not initialized, or 0 if it was initialized to 0), and the program
    // will proceed with 0 seconds, which is a silent failure.

    long long hours = totalSeconds / 3600;
    long long remainingAfterHours = totalSeconds % 3600;
    long long minutes = remainingAfterHours / 60;
    long long remainingSeconds = remainingAfterHours % 60;

    std::cout << hours << "h " << minutes << "m " << remainingSeconds << "s" << std::endl;

    return 0;
}