#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

class Rectangle {
private:
    double width;
    double height;

public:
    // Parameterized constructor
    Rectangle(double w, double h) {
        // Robustness Issue:
        // Only checks if dimensions are strictly less than 0.
        // It should check if they are less than or equal to 0,
        // as 0.0 is not a positive dimension.
        if (w < 0) { // Should be w <= 0
            width = 1.0;
        } else {
            width = w;
        }

        if (h < 0) { // Should be h <= 0
            height = 1.0;
        } else {
            height = h;
        }
    }

    // Method to calculate area
    double calculateArea() {
        return width * height;
    }

    // Method to calculate perimeter
    double calculatePerimeter() {
        return 2 * (width + height);
    }
};

int main() {
    std::vector<std::pair<double, double>> test_inputs = {
        {5.0, 10.0},
        {-2.0, 8.0},
        {7.0, -3.0},
        {-4.0, -6.0},
        {0.0, 9.0},
        {6.0, 0.0},
        {0.0, 0.0},
        {1000.0, 2000.0}
    };

    for (const auto& p : test_inputs) {
        Rectangle rect(p.first, p.second);
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Input: (" << p.first << ", " << p.second << ") -> ";
        std::cout << "Area: " << rect.calculateArea() << ", ";
        std::cout << "Perimeter: " << rect.calculatePerimeter() << std::endl;
    }

    return 0;
}