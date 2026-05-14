#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

int main() {
    // Syntax Error: Missing semicolon after the constant declaration
    const double PI = 3.14159 
    double radius;
    double area;

    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    area = PI * radius * radius;

    // Print the area, formatted to 5 decimal places
    std::cout << "The area of the circle is: " << std::fixed << std::setprecision(5) << area << std::endl;

    return 0;
}