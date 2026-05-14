#include <iostream>
#include <cmath> // Included but M_PI is not used directly
#include <iomanip> // For std::fixed, std::setprecision

// Core logic wrapped in a function to allow for a simple driver in JSON
void solve() {
    double r; // Uninformative variable name
    std::cout << "Enter the radius of the circle: ";
    std::cin >> r;

    // Pi is defined locally, not using M_PI from cmath or a global constant.
    // This is less efficient if the function were called repeatedly.
    const double pi = 3.14159; 

    double a = pi * r * r; // Area calculation using uninformative variable
    double c = 2 * pi * r; // Circumference calculation using uninformative variable

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Area Is: " << a << std::endl; // Inconsistent output message style
    std::cout << "Circumference Is: " << c << std::endl;
}

int main() {
    solve();
    return 0;
}