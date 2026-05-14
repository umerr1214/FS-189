#include <iostream>

int main() {
    char score_char; // Semantic error: Using char to store a numerical score (0-100)
    std::cout << "Enter score (0-100): ";
    std::cin >> score_char;

    // The comparison `score_char >= 60` will compare the ASCII value of the character
    // entered by the user with the integer 60, not the numerical value of the score.
    // For example, if the user enters '7' (ASCII 55), the condition '7' >= 60 (55 >= 60) is false,
    // leading to 'Fail', even though a score of 70 should be 'Pass'.
    if (score_char >= 60) { 
        std::cout << "Pass" << std::endl;
    } else {
        std::cout << "Fail" << std::endl;
    }

    return 0;
}