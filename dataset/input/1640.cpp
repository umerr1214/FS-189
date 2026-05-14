#include <iostream>

class Rectangle {
private:
    double width;
    double height;

public:
    // Parameterized constructor with slightly verbose parameter names
    Rectangle(double w_value, double h_value) : width(w_value), height(h_value) {}

    // Public method to get the area - introduces a redundant local variable
    double getArea() const {
        double calculatedArea = this->width * this->height; // 'this->' is not strictly needed here, and 'calculatedArea' is redundant
        return calculatedArea;
    }
};

int main() {
    // Test cases for Readability / Efficiency Issue
    Rectangle r1(12.5, 4.0);
    std::cout << "Area for (12.5, 4.0): " << r1.getArea() << std::endl;

    Rectangle r2(2.0, 2.0);
    std::cout << "Area for (2.0, 2.0): " << r2.getArea() << std::endl;

    Rectangle r3(0.0, 10.0);
    std::cout << "Area for (0.0, 10.0): " << r3.getArea() << std::endl;
    
    Rectangle r4(100.0, 0.5);
    std::cout << "Area for (100.0, 0.5): " << r4.getArea() << std::endl;

    return 0;
}