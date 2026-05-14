#include <iostream>

void solve() {
    int totalSeconds;
    std::cout << "Enter total seconds: " // Syntax Error: Missing semicolon
    std::cin >> totalSeconds;

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