#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

int main() {
    // Semantic Error: PI is declared as an integer, losing precision.
    // While syntactically correct, it semantically misrepresents the value of Pi
    // required for accurate floating-point calculations.
    const int PI = 3; 
    double radius;
    double area;

    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    area = PI * radius * radius; // Calculation uses the integer PI

    // Print the area, formatted to 5 decimal places
    std::cout << "The area of the circle is: " << std::fixed << std::setprecision(5) << area << std::endl;

    return 0;
}