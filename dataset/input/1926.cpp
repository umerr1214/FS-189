#include <iostream>

class Rectangle {
private: // Semantic Error: length and width are private
    double length;
    double width;

public:
    // Default constructor
    Rectangle() : length(0.0), width(0.0) {}

    // Parameterized constructor
    Rectangle(double l, double w) : length(l), width(w) {}
};

int main() {
    Rectangle r1;
    // Attempting to access private members directly, which is a semantic error
    // This code will not compile due to access restrictions.
    // std::cout << "Default Rectangle: Length = " << r1.length << ", Width = " << r1.width << std::endl;

    Rectangle r2(10.5, 5.2);
    // std::cout << "Parameterized Rectangle: Length = " << r2.length << ", Width = " << r2.width << std::endl;

    // To fix, one would need public getter methods or make members public.
    std::cout << "Rectangle objects created. Cannot print members due to private access." << std::endl;

    return 0;
}