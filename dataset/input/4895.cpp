#include <iostream>
#include <cmath> // For M_PI

// Function to calculate area of a circle (LOGICAL ERROR HERE)
double calculateArea(double radius) {
    return 2 * M_PI * radius; // Logical error: This calculates circumference, not area. Should be M_PI * radius * radius.
}

// Function to calculate area of a rectangle
double calculateArea(double length, double width) {
    return length * width;
}

int main() {
    int choice;
    std::cout << "Choose area to calculate:\n";
    std::cout << "1. Circle\n";
    std::cout << "2. Rectangle\n";
    std::cout << "Enter your choice (1 or 2): ";
    std::cin >> choice;

    if (choice == 1) {
        double radius;
        std::cout << "Enter the radius of the circle: ";
        std::cin >> radius;
        std::cout << "Area of circle: " << calculateArea(radius) << std::endl;
    } else if (choice == 2) {
        double length, width;
        std::cout << "Enter the length of the rectangle: ";
        std::cin >> length;
        std::cout << "Enter the width of the rectangle: ";
        std::cin >> width;
        std::cout << "Area of rectangle: " << calculateArea(length, width) << std::endl;
    } else {
        std::cout << "Invalid choice." << std::endl;
    }

    return 0;
}