#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

class Rectangle {
private:
    double len; // Inconsistent and less descriptive naming
    double wid; // compared to 'length' and 'width'

public:
    // Constructor with default arguments
    Rectangle(double length = 1.0, double width = 1.0) {
        // Not using initializer list, which is less efficient for member initialization
        this->len = length; // Redundant use of 'this->'
        this->wid = width;  // for simple assignments
    }

    // Getters are not marked 'const', which is a readability/best practice issue
    double getLength() {
        return len;
    }

    double getWidth() {
        return wid;
    }

    double calculateArea() { // Method name is slightly verbose, 'getArea' is more common
        return len * wid;
    }

    void showDimensions(const std::string& label) { // Not marked 'const'
        std::cout << label << ": Length = " << std::fixed << std::setprecision(1) << len
                  << ", Width = " << std::fixed << std::setprecision(1) << wid
                  << ", Area = " << std::fixed << std::setprecision(1) << calculateArea() << std::endl;
    }
};

int main() {
    // Demonstrate creating Rectangle objects
    
    // 1. Using default arguments (length = 1.0, width = 1.0)
    Rectangle r1;
    r1.showDimensions("Rectangle A (Default)");

    // 2. Using one argument (length = 5.0, width = 1.0)
    Rectangle r2(5.0);
    r2.showDimensions("Rectangle B (One argument)");

    // 3. Using both arguments (length = 3.0, width = 4.0)
    Rectangle r3(3.0, 4.0);
    r3.showDimensions("Rectangle C (Both arguments)");

    // Create another rectangle to show consistent behavior
    Rectangle r4(10.0);
    r4.showDimensions("Rectangle D (Another one)");

    return 0;
}