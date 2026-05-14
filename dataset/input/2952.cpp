#include <iostream>

class Box {
public:
    double length;
    double width;

    // SEMANTIC ERROR: Cannot use a parameter (length) as a default argument
    // for another parameter (width) in the same function signature.
    // Default arguments must be compile-time constants or expressions that do
    // not depend on other parameters of the same function.
    Box(double length, double width = length) : length(length), width(width) {}

    double getArea() const {
        return length * width;
    }
};

int main() {
    // Test cases - this code will not compile due to the semantic error
    Box b1(10.0, 5.0); // Intended: length = 10, width = 5
    Box b2(7.0);       // Intended: length = 7, width defaults to 7 (square base)

    std::cout << "Box 1 (10x5) area: " << b1.getArea() << std::endl;
    std::cout << "Box 2 (7x7) area: " << b2.getArea() << std::endl;

    return 0;
}