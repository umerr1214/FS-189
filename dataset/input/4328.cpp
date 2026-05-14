#include <iostream>
#include <string>

int main() {
    int score;
    std::cout << "Enter score: ";
    std::cin >> score;

    // Readability/Efficiency Issue:
    // Uses an intermediate string variable and assignment instead of directly
    // printing 'Pass' or 'Fail'. This adds minor overhead (string construction/copy)
    // and makes the code slightly less concise than direct printing.
    std::string result;
    if (score >= 60) {
        result = "Pass";
    } else {
        result = "Fail";
    }
    std::cout << result << std::endl;

    return 0;
}