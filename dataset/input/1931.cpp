#include <iostream>
#include <string>

class Rectangle {
private:
    double length;
    double width;

public:
    // Constructor
    Rectangle(double l = 1.0, double w = 1.0) : length(l), width(w) {
        if (length <= 0) length = 1.0;
        if (width <= 0) width = 1.0;
    }

    // Getters
    double getLength() const { return length; }
    double getWidth() const { return width; }

    // Setters
    void setLength(double l) {
        if (l <= 0) {
            std::cout << "Error: Invalid length (value " << l << "). Length must be positive." << std::endl;
            // Logical error: The member 'length' is still updated even if the value is invalid.
            length = l; // Should NOT update here
        } else {
            length = l;
        }
    }

    void setWidth(double w) {
        if (w <= 0) {
            std::cout << "Error: Invalid width (value " << w << "). Width must be positive." << std::endl;
            // Logical error: The member 'width' is still updated even if the value is invalid.
            width = w; // Should NOT update here
        } else {
            width = w;
        }
    }

    double calculateArea() const {
        return length * width;
    }

    void printDimensions() const {
        std::cout << "Length: " << length << ", Width: " << width << std::endl;
    }
};

int main() {
    Rectangle rect(5.0, 10.0);
    std::cout << "Initial dimensions: ";
    rect.printDimensions();

    rect.setLength(7.5);
    std::cout << "After setting length to 7.5: ";
    rect.printDimensions();

    rect.setWidth(2.0);
    std::cout << "After setting width to 2.0: ";
    rect.printDimensions();

    rect.setLength(-3.0); // Invalid
    std::cout << "After setting length to -3.0: ";
    rect.printDimensions(); // Expected: 7.5, 2. Actual: -3.0, 2.0 (Logical Error)

    rect.setWidth(0.0); // Invalid
    std::cout << "After setting width to 0.0: ";
    rect.printDimensions(); // Expected: -3.0, 2. Actual: -3.0, 0.0 (Logical Error)

    rect.setLength(15.0);
    std::cout << "After setting length to 15.0: ";
    rect.printDimensions();

    return 0;
}