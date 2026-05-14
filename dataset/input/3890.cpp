#include <iostream>
#include <cmath> // Included but not strictly necessary for direct float comparisons

int main() {
    float x, y, z; // Using float instead of double, which can lead to precision issues

    std::cout << "Enter side X: ";
    std::cin >> x;
    std::cout << "Enter side Y: ";
    std::cin >> y;
    std::cout << "Enter side Z: ";
    std::cin >> z;

    // Input validation for positive numbers and numeric input
    if (std::cin.fail() || x <= 0 || y <= 0 || z <= 0) {
        std::cout << "Invalid input: Side lengths must be positive numbers." << std::endl; // Using std::endl
        return 1;
    }

    // Check for invalid triangle conditions
    if ((x + y <= z) || (x + z <= y) || (y + z <= x)) {
        std::cout << "The given side lengths do not form a valid triangle." << std::endl;
    } else {
        // Determine triangle type with verbose and slightly redundant logic
        if (x == y) {
            if (y == z) {
                std::cout << "This is an equilateral triangle." << std::endl;
            } else {
                std::cout << "This is an isosceles triangle." << std::endl;
            }
        } else if (x == z) {
            // This 'else if' branch is redundant if x==y==z was already caught,
            // but it correctly identifies isosceles if only x==z.
            std::cout << "This is an isosceles triangle." << std::endl;
        } else if (y == z) {
            // This 'else if' branch is also redundant if x==y==z or x==z was already caught,
            // but it correctly identifies isosceles if only y==z.
            std::cout << "This is an isosceles triangle." << std::endl;
        } else {
            std::cout << "This is a scalene triangle." << std::endl;
        }
    }

    return 0;
}