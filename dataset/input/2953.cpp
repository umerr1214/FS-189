#include <iostream>
#include <string>
#include <sstream>
#include <limits> // For NaN sentinel

class Box {
private:
    double m_length;
    double m_width;

public:
    // Constructor with a default argument for width.
    // Uses NaN as a sentinel to determine if width was provided or should default to length.
    // Robustness issue: Does not validate if length or width are non-positive.
    Box(double length, double width_arg = std::numeric_limits<double>::quiet_NaN())
        : m_length(length),
          m_width(std::isnan(width_arg) ? length : width_arg) {}

    // Robustness issue: Calculates area directly without checking for valid (positive) dimensions.
    // This can lead to negative or zero area for non-positive inputs.
    double getArea() const {
        return m_length * m_width;
    }

    double getLength() const {
        return m_length;
    }

    double getWidth() const {
        return m_width;
    }
};

int main() {
    // Test cases to demonstrate robustness issue with non-positive dimensions
    Box box1(5.0, 3.0);      // Normal case
    Box box2(5.0);           // Default width (5.0)
    Box box3(-5.0, 3.0);     // Negative length
    Box box4(5.0, -3.0);     // Negative width
    Box box5(-5.0, -3.0);    // Both negative
    Box box6(0.0, 3.0);      // Zero length
    Box box7(5.0, 0.0);      // Zero width
    Box box8(0.0);           // Default width (0.0)

    std::cout << "Box 1 (5.0x3.0): Length=" << box1.getLength() << ", Width=" << box1.getWidth() << ", Area=" << box1.getArea() << std::endl;
    std::cout << "Box 2 (5.0x5.0): Length=" << box2.getLength() << ", Width=" << box2.getWidth() << ", Area=" << box2.getArea() << std::endl;
    std::cout << "Box 3 (-5.0x3.0): Length=" << box3.getLength() << ", Width=" << box3.getWidth() << ", Area=" << box3.getArea() << std::endl;
    std::cout << "Box 4 (5.0x-3.0): Length=" << box4.getLength() << ", Width=" << box4.getWidth() << ", Area=" << box4.getArea() << std::endl;
    std::cout << "Box 5 (-5.0x-3.0): Length=" << box5.getLength() << ", Width=" << box5.getWidth() << ", Area=" << box5.getArea() << std::endl;
    std::cout << "Box 6 (0.0x3.0): Length=" << box6.getLength() << ", Width=" << box6.getWidth() << ", Area=" << box6.getArea() << std::endl;
    std::cout << "Box 7 (5.0x0.0): Length=" << box7.getLength() << ", Width=" << box7.getWidth() << ", Area=" << box7.getArea() << std::endl;
    std::cout << "Box 8 (0.0x0.0): Length=" << box8.getLength() << ", Width=" << box8.getWidth() << ", Area=" << box8.getArea() << std::endl;

    return 0;
}