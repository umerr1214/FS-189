#include <iostream>
#include <string>

std::string classifyTriangle(int a, int b, int c) {
    if (a == b && b == c) {
        return "Equilateral";
    } else if (a == b || b == c || a == c) {
        return "Isosceles";
    } else {
        return "Scalene";
    }
}

int main() {
    int s1, s2, s3;
    std::cout << "Enter three side lengths: ";
    std::cin >> s1 >> s2 >> s3;
    std::string type = classifyTriangle(s1, s2, s3);
    std::cout << "The triangle is: " << type << std::endl // MISSING SEMICOLON HERE
    return 0;
}