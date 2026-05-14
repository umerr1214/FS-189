#include <iostream>

class Box {
public:
    double length;
    double width;

    // Constructor with a default argument for width using a sentinel value
    // A negative value for width indicates that it should default to length.
    Box(double l, double w = -1.0) : length(l) {
        if (w < 0) { // If width is negative (sentinel), default to length
            width = l;
        } else {
            width = w;
        }
    }

    double getArea() const {
        return length * width;
    }
} // SYNTAX ERROR: Missing semicolon here after class definition

int main() {
    // Test cases
    Box b1(10.0, 5.0); // length = 10, width = 5
    Box b2(7.0);       // length = 7, width defaults to 7 (square base)

    std::cout << "Box 1 (10x5) area: " << b1.getArea() << std::endl;
    std::cout << "Box 2 (7x7) area: " << b2.getArea() << std::endl;

    return 0;
}