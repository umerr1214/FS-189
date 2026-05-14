#include <iostream>

class Box {
public:
    double length;
    double width;

    // LOGICAL ERROR: The default argument for width is a fixed value (1.0)
    // instead of defaulting to the provided length.
    Box(double l, double w = 1.0) : length(l), width(w) {
        // This constructor incorrectly makes 'width' always 1.0 if only 'length' is provided.
        // It does not default 'width' to 'length' as required.
    }

    double getArea() const {
        return length * width;
    }
};

int main() {
    // Test cases
    Box b1(10.0, 5.0); // length = 10, width = 5. Area should be 50.0 (Correct)
    Box b2(7.0);       // length = 7, width defaults to 1.0. Area will be 7.0 (Incorrect, should be 49.0)

    std::cout << "Box 1 (10x5) area: " << b1.getArea() << std::endl;
    std::cout << "Box 2 (7x1) area: " << b2.getArea() << std::endl; // Output will show 7x1, not 7x7
    
    return 0;
}