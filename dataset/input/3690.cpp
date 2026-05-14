#include <iostream>
#include <cmath> // For sqrt and pow
#include <iomanip> // For setprecision

struct Point {
    // SEMANTIC ERROR: Coordinates defined as int, but problem specifies double.
    // This leads to truncation when reading double inputs.
    int x;
    int y;
};

int main() {
    Point p1, p2;

    std::cout << "Enter coordinates for Point 1 (x y): ";
    // Reading double values into int members causes truncation (e.g., 1.2 becomes 1)
    std::cin >> p1.x >> p1.y;

    std::cout << "Enter coordinates for Point 2 (x y): ";
    std::cin >> p2.x >> p2.y;

    // Calculations will proceed with truncated integer values
    double dx = static_cast<double>(p2.x) - static_cast<double>(p1.x);
    double dy = static_cast<double>(p2.y) - static_cast<double>(p1.y);

    double distance = std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "The Euclidean distance between (" << static_cast<double>(p1.x) << ", " << static_cast<double>(p1.y) << ") and ("
              << static_cast<double>(p2.x) << ", " << static_cast<double>(p2.y) << ") is " << distance << std::endl;

    return 0;
}