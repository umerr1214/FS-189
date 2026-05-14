#include <iostream>
#include <string>

std::string classifyTriangle(int a, int b, int c) {
    // Logical error: The condition for Isosceles is checked before Equilateral.
    // An equilateral triangle (e.g., 3,3,3) satisfies the Isosceles condition (a==b || b==c || a==c)
    // and will be incorrectly classified as "Isosceles" instead of "Equilateral".
    if (a == b || b == c || a == c) {
        return "Isosceles";
    } else if (a == b && b == c) { // This branch will never be reached for equilateral triangles.
        return "Equilateral";
    } else {
        return "Scalene";
    }
}

int main() {
    int s1, s2, s3;
    std::cout << "Enter three side lengths: ";
    std::cin >> s1 >> s2 >> s3;
    std::string type = classifyTriangle(s1, s2, s3);
    std::cout << "The triangle is: " << type << std::endl;
    return 0;
}