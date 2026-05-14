#include <iostream>
#include <string>

int main() {
    int s1, s2, s3;

    // Read three integer side lengths from standard input
    // This version does not check for std::cin errors (e.g., non-integer input)
    // If input fails, s1, s2, s3 might contain garbage or 0, leading to incorrect classification
    std::cout << "Enter three integer side lengths: ";
    std::cin >> s1 >> s2 >> s3;

    // Classify the triangle type
    if (s1 == s2 && s2 == s3) {
        std::cout << "Equilateral" << std::endl;
    } else if (s1 == s2 || s1 == s3 || s2 == s3) {
        std::cout << "Isosceles" << std::endl;
    } else {
        std::cout << "Scalene" << std::endl;
    }

    return 0;
}