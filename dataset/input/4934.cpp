#include <iostream>
#include <string>

int main() {
    int s1, s2, s3; // Non-descriptive variable names

    std::cout << "Enter three integer side lengths: ";
    std::cin >> s1 >> s2 >> s3;

    // Convoluted conditional logic for classification
    if (s1 == s2) {
        if (s2 == s3) {
            std::cout << "Equilateral" << std::endl; // Repeated string literal
        } else {
            // s1 == s2 but s2 != s3, so it's isosceles
            std::cout << "Isosceles" << std::endl; // Repeated string literal
        }
    } else { // s1 != s2
        if (s1 == s3 || s2 == s3) {
            std::cout << "Isosceles" << std::endl; // Repeated string literal
        } else {
            std::cout << "Scalene" << std::endl; // Repeated string literal
        }
    }

    return 0;
}