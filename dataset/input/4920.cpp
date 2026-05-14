#include <iostream>

void solve() {
    int totalSeconds; // Semantic Error: Variable declared but not initialized
    std::cout << "Enter total seconds: ";
    // std::cin >> totalSeconds; // Input statement is commented out, so totalSeconds remains uninitialized.

    // Using an uninitialized variable leads to undefined behavior.
    // The values of hours, minutes, and seconds will be unpredictable.
    int hours = totalSeconds / 3600;
    int remainingSeconds = totalSeconds % 3600;
    int minutes = remainingSeconds / 60;
    int seconds = remainingSeconds % 60;

    std::cout << "Hours: " << hours << std::endl;
    std::cout << "Minutes: " << minutes << std::endl;
    std::cout << "Seconds: " << seconds << std::endl;
}

int main() {
    solve();
    return 0;
}