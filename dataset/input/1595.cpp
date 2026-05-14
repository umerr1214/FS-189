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

    // Logical error: Area is calculated by adding instead of multiplying
    double calculateArea() const {
        return length + width; // Incorrect logic for area calculation
    }

    void display() const {
        std::cout << "Rectangle: Length = " << std::fixed << std::setprecision(2) << length
                  << ", Width = " << std::fixed << std::setprecision(2) << width
                  << ", Area = " << std::fixed << std::setprecision(2) << calculateArea() << std::endl;
    }
};

int main() {
    Rectangle r1; // Default arguments (1.0, 1.0)
    Rectangle r2(5.0); // One argument (length = 5.0, width = 1.0)
    Rectangle r3(4.0, 6.0); // Both arguments (4.0, 6.0)

    std::cout << "Demonstrating Rectangle objects (with logical error in area calculation):" << std::endl;
    r1.display();
    r2.display();
    r3.display();

    return 0;
}