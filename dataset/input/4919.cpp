#include <iostream>

void solve() {
    int totalSeconds;
    std::cout << "Enter total seconds: ";
    std::cin >> totalSeconds;

    int hours = totalSeconds / 3600;
    // Logical Error: Minutes are calculated from totalSeconds directly,
    // instead of the remaining seconds after hours are extracted.
    // This will include the hours component in the minutes calculation.
    int minutes = totalSeconds / 60; 
    
    // Logical Error: Seconds are calculated from totalSeconds directly,
    // instead of the remaining seconds after hours and minutes are extracted.
    int seconds = totalSeconds % 60; 

    std::cout << "Hours: " << hours << std::endl;
    std::cout << "Minutes: " << minutes << std::endl;
    std::cout << "Seconds: " << seconds << std::endl;
}

int main() {
    solve();
    return 0;
}