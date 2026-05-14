#include <iostream>
#include <string>

std::string getTriangleType(double s1, double s2, double s3) {
    if (s1 <= 0 || s2 <= 0 || s3 <= 0 ||
        !(s1 + s2 > s3 && s1 + s3 > s2 && s2 + s3 > s1)) {
        return "Invalid Triangle";
    }

    if (s1 == s2 && s2 == s3) {
        return "Equilateral Triangle";
    }
    else if (s1 == s2 || s1 == s3 || s2 == s3) {
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
    std::cout << "Enter side 3: " // Missing semicolon here, causing a syntax error
    std::cin >> side3;

    std::string result = getTriangleType(side1, side2, side3);
    std::cout << "The triangle is: " << result << std::endl;

    return 0;
}