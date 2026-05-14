#include <iostream>
#include <limits> // Required for std::numeric_limits
#include <iomanip> // Required for std::fixed and std::setprecision

int main() {
    int choice;
    double radius, side, base, height;
    const double PI = 3.14159;

    while (true) {
        std::cout << "\n--- Area Calculator Menu ---\n";
        std::cout << "1. Calculate Area of Circle\n";
        std::cout << "2. Calculate Area of Square\n";
        std::cout << "3. Calculate Area of Triangle\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                std::cout << "Enter radius of the circle: ";
                std::cin >> radius;
                if (std::cin.fail() || radius < 0) {
                    std::cout << "Invalid radius. Please enter a non-negative number.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                std::cout << "Area of circle: " << std::fixed << std::setprecision(7) << PI * radius * radius << std::endl;
                break;
            case 2:
                std::cout << "Enter side length of the square: ";
                std::cin >> side;
                if (std::cin.fail() || side < 0) {
                    std::cout << "Invalid side length. Please enter a non-negative number.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                std::cout << "Area of square: " << std::fixed << std::setprecision(7) << side * side << std::endl;
                break;
            case 3:
                std::cout << "Enter base of the triangle: ";
                std::cin >> base;
                std::cout << "Enter height of the triangle: ";
                std::cin >> height;
                if (std::cin.fail() || base < 0 || height < 0) {
                    std::cout << "Invalid dimensions. Please enter non-negative numbers.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                std::cout << "Area of triangle: " << std::fixed << std::setprecision(7) << base * height << std::endl; // Logical error: Missing 0.5 for triangle area
                break;
            case 4:
                std::cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
                break;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}