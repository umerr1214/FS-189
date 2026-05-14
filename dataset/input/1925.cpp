#include <iostream>

class Rectangle {
public:
    double length;
    double width;

    // Default constructor
    Rectangle() : length(0.0), width(0.0) {}

    // Parameterized constructor (Logical Error: Swaps length and width)
    Rectangle(double l, double w) : length(w), width(l) {} // Should be length(l), width(w)
};

int main() {
    Rectangle r1;
    std::cout << "Default Rectangle: Length = " << r1.length << ", Width = " << r1.width << std::endl;

    Rectangle r2(10.5, 5.2);
    // Expected: Length = 10.5, Width = 5.2
    // Actual (due to logical error): Length = 5.2, Width = 10.5
    std::cout << "Parameterized Rectangle: Length = " << r2.length << ", Width = " << r2.width << std::endl;

    return 0;
}