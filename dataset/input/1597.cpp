#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

class Rectangle {
private:
    double length;
    double width;

public:
    // Constructor with default arguments
    Rectangle(double length = 1.0, double width = 1.0) {
        this->length = length; // Directly assigns potentially invalid values
        this->width = width;   // without validation
    }

    double getLength() const {
        return length;
    }

    double getWidth() const {
        return width;
    }

    // Calculates area. Will return negative if one dimension is negative.
    double getArea() const {
        return length * width;
    }

    void displayInfo(const std::string& name) const {
        std::cout << name << ": Length = " << std::fixed << std::setprecision(1) << length
                  << ", Width = " << std::fixed << std::setprecision(1) << width
                  << ", Area = " << std::fixed << std::setprecision(1) << getArea() << std::endl;
    }
};

int main() {
    // Demonstrate creating Rectangle objects
    
    // 1. Using default arguments (length = 1.0, width = 1.0)
    Rectangle r1;
    r1.displayInfo("Rectangle 1 (Default)");

    // 2. Using one argument (length = 5.0, width = 1.0)
    Rectangle r2(5.0);
    r2.displayInfo("Rectangle 2 (One argument)");

    // 3. Using both arguments (length = 3.0, width = 4.0)
    Rectangle r3(3.0, 4.0);
    r3.displayInfo("Rectangle 3 (Both arguments)");

    // Demonstrate a robustness issue: allowing negative dimensions
    // A real-world rectangle cannot have negative dimensions,
    // and its area should not be negative.
    Rectangle r_robust(-2.0, 5.0);
    r_robust.displayInfo("Rectangle 4 (Robustness issue)");

    return 0;
}