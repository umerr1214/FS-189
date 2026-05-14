#include <iostream>
#include <string>
#include <cmath> // Included for potential future use, but not for the error itself

std::string getTriangleType(double s1, double s2, double s3) {
    // Semantic Error: Direct comparison of floating-point numbers (doubles) using `==`.
    // While this code might produce correct results for exact inputs like `5.0`, `5.0`, `5.0`,
    // it is semantically incorrect and unsafe for general floating-point comparisons.
    // Due to precision issues, two theoretically equal floating-point numbers might not be exactly equal
    // when represented in binary. A robust comparison should use an epsilon (e.g., `fabs(s1 - s2) < EPSILON`).

    if (s1 <= 0 || s2 <= 0 || s3 <= 0 ||
        !(s1 + s2 > s3 && s1 + s3 > s2 && s2 + s3 > s1)) {
        return "Invalid Triangle";
    }

    if (s1 == s2 && s2 == s3) { // Semantic issue: direct double comparison
        return "Equilateral Triangle";
    }
    else if (s1 == s2 || s1 == s3 || s2 == s3) { // Semantic issue: direct double comparison
        return "Isosceles Triangle";
    }
    else {
        return "Scalene Triangle";
    }
}

int main() {
    double side1, side2, side3;
    std::cout << "Enter side 1: ";
    std::cin >> side1;
    std::cout << "Enter side 2: ";
    std::cin >> side2;
    std::cout << "Enter side 3: ";
    std::cin >> side3;

    std::string result = getTriangleType(side1, side2, side3);
    std::cout << "The triangle is: " << result << std::endl;

    return 0;
}