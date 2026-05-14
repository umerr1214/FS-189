#include <iostream>
#include <string>
#include <sstream>
#include <limits> // For NaN sentinel
#include <cmath>  // For std::isnan

class Box {
private:
    double m_length;
    double m_width;

public:
    // Constructor with a default argument for width.
    // Uses std::numeric_limits<double>::quiet_NaN() as a robust sentinel value
    // to determine if width was explicitly provided or should default to length.
    // Uses an initializer list for efficient and clean member initialization.
    Box(double length, double width_arg = std::numeric_limits<double>::quiet_NaN())
        : m_length(length),
          m_width(std::isnan(width_arg) ? length : width_arg) {}

    // Provides the area of the box. Marked const as it does not modify the object state.
    double getArea() const {
        return m_length * m_width;
    }

    // Provides the length of the box. Marked const.
    double getLength() const {
        return m_length;
    }

    // Provides the width of the box. Marked const.
    double getWidth() const {
        return m_width;
    }
};

int main() {
    // Test cases for the correctly implemented Box class
    Box box1(10.0, 5.0); // Box with explicit length and width
    Box box2(7.5);       // Box with only length, width defaults to length
    Box box3(1.0, 1.0);  // Square box
    Box box4(12.3);      // Another box with default width

    std::cout << "Box 1 (10.0x5.0): Length=" << box1.getLength() << ", Width=" << box1.getWidth() << ", Area=" << box1.getArea() << '\n';
    std::cout << "Box 2 (7.5x7.5): Length=" << box2.getLength() << ", Width=" << box2.getWidth() << ", Area=" << box2.getArea() << '\n';
    std::cout << "Box 3 (1.0x1.0): Length=" << box3.getLength() << ", Width=" << box3.getWidth() << ", Area=" << box3.getArea() << '\n';
    std::cout << "Box 4 (12.3x12.3): Length=" << box4.getLength() << ", Width=" << box4.getWidth() << ", Area=" << box4.getArea() << '\n';

    return 0;
}