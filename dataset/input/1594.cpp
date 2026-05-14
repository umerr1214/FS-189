#include <iostream>
#include <iomanip>

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l = 1.0, double w = 1.0) : length(l), width(w) {
        if (length < 0) length = 0;
        if (width < 0) width = 0;
    }

    double getLength() const { return length; }
    double getWidth() const { return width; }

    double calculateArea() const {
        return length * width;
    }

    void display() const {
        std::cout << "Rectangle: Length = " << std::fixed << std::setprecision(2) << length
                  << ", Width = " << std::fixed << std::setprecision(2) << width
                  << ", Area = " << std::fixed << std::setprecision(2) << calculateArea() << std::endl;
    }
} // Syntax Error: Missing semicolon after class definition

int main() {
    Rectangle r1; // Default arguments
    Rectangle r2(5.0); // One argument (length = 5.0, width = 1.0)
    Rectangle r3(4.0, 6.0); // Both arguments

    std::cout << "Demonstrating Rectangle objects:" << std::endl;
    r1.display();
    r2.display();
    r3.display();

    return 0;
}