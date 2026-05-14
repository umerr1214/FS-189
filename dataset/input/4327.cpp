#include <iostream>
#include <string>

int main() {
    int score;
    std::cout << "Enter score: ";
    std::cin >> score;

    // Robustness Issue: Does not validate if the score is within the 0-100 range.
    // It will process any integer input, even if outside the specified range,
    // potentially giving a misleading 'Pass' or 'Fail' for invalid scores.
    if (score >= 60) {
        std::cout << "Pass" << std::endl;
    } else {
        std::cout << "Fail" << std::endl;
    }

    return 0;
}