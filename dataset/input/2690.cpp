#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

class Rectangle {
private:
    double width_val;  // Readability Issue: Non-descriptive variable name
    double height_val; // Readability Issue: Non-descriptive variable name

public:
    // Parameterized constructor with readability/efficiency issues
    Rectangle(double initialWidth, double initialHeight) {
        // Readability/Efficiency Issue: Redundant conditional checks
        if (initialWidth <= 0.0) {
            this->width_val = 1.0;
        } else {
            if (initialWidth > 0.0) { // This check is redundant; initialWidth must be > 0 here
                this->width_val = initialWidth;
            } else {
                // This else branch is unreachable
                this->width_val = 1.0;
            }
        }

        if (initialHeight <= 0.0) {
            this->height_val = 1.0;
        } else {
            if (initialHeight > 0.0) { // This check is redundant
                this->height_val = initialHeight;
            } else {
                // This else branch is unreachable
                this->height_val = 1.0;
            }
        }
    }

    // Method to calculate area with an efficiency issue
    double calculateArea() {
        double resultArea = width_val * height_val; // Efficiency Issue: Unnecessary temporary variable
        return resultArea;
    }

    // Method to calculate perimeter with an efficiency issue
    double calculatePerimeter() {
        // Efficiency Issue: Less efficient calculation (summing four sides instead of 2 * (w+h))
        return width_val + height_val + width_val + height_val;
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