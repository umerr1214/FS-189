#include <iostream>

class Rectangle {
public:
    double length;
    double width;

    // Default constructor
    Rectangle() : length(0.0), width(0.0) {}

    // Parameterized constructor
    Rectangle(double l, double w) : length(l), width(w) {}
}; // Missing semicolon here, will cause a syntax error

int main() {
    // This part of the code might not be reached or compile due to the syntax error
    Rectangle r1;
    std::cout << "Default Rectangle: Length = " << r1.length << ", Width = " << r1.width << std::endl;

    Rectangle r2(10.5, 5.2);
    std::cout << "Parameterized Rectangle: Length = " << r2.length << ", Width = " << r2.width << std::endl;

    return 0;
}