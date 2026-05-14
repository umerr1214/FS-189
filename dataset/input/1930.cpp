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
            std::cout << "Error: Invalid length (value " << l << "). Length must be positive and was not updated." << std::endl;
        } else {
            length = l;
        }
    }

    void setWidth(double w) {
        if (w <= 0) {
            std::cout << "Error: Invalid width (value " << w << "). Width must be positive and was not updated." << std::endl;
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
}; // Missing semicolon here - SYNTAX ERROR

int main() {
    Rectangle rect(5.0, 10.0);
    std::cout << "Initial dimensions: ";
    rect.printDimensions(); // Length: 5, Width: 10

    rect.setLength(7.5);
    std::cout << "After setting length to 7.5: ";
    rect.printDimensions(); // Length: 7.5, Width: 10

    rect.setWidth(2.0);
    std::cout << "After setting width to 2.0: ";
    rect.printDimensions(); // Length: 7.5, Width: 2

    rect.setLength(-3.0); // Invalid
    std::cout << "After setting length to -3.0: ";
    rect.printDimensions(); // Length: 7.5, Width: 2

    rect.setWidth(0.0); // Invalid
    std::cout << "After setting width to 0.0: ";
    rect.printDimensions(); // Length: 7.5, Width: 2

    rect.setLength(15.0);
    std::cout << "After setting length to 15.0: ";
    rect.printDimensions(); // Length: 15, Width: 2

    return 0;
}