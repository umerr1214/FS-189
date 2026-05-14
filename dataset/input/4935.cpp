#include <iostream>
#include <string>

int main() {
    int side1, side2, side3;

    std::cout << "Enter three integer side lengths: ";
    std::cin >> side1 >> side2 >> side3;

    // Classify the triangle type based on side lengths
    if (side1 == side2 && side2 == side3) {
        std::cout << "Equilateral" << std::endl;
    } else if (side1 == side2 || side1 == side3 || side2 == side3) {
        std::cout << "Isosceles" << std::endl;
    } else {
        std::cout << "Scalene" << std::endl;
    }

    return 0;
}