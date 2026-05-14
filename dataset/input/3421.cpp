#include <iostream>
#include <cmath> // For M_PI on some systems
#include <iomanip> // For std::fixed, std::setprecision

// Define M_PI if not available (e.g., on some compilers without _USE_MATH_DEFINES)
#ifndef M_PI
#define M_PI 3.14159
#endif

// Core logic wrapped in a function to allow for a simple driver in JSON
void solve() {
    double radius;
    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius; // No input validation here

    // If a non-numeric value is entered, cin.fail() will be true,
    // and subsequent operations might use uninitialized 'radius' or 0,
    // potentially leading to undefined behavior or incorrect calculations.
    // The program will also proceed without checking for a negative radius.

    double area = M_PI * radius * radius;
    double circumference = 2 * M_PI * radius;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Area: " << area << std::endl;
    std::cout << "Circumference: " << circumference << std::endl;
}

int main() {
    solve(); // main calls the solve function
    return 0;
}