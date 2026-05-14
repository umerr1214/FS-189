#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

class Rectangle {
public:
    double length; // Public for simplicity in testing, though usually private with getters/setters
    double width;

    // Default constructor
    Rectangle() {
        length = 0.0;
        width = 0.0;
    }

    // Parameterized constructor - Robustness issue: no input validation
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double getLength() const {
        return length;
    }

    double getWidth() const {
        return width;
    }

    double getArea() const {
        return length * width;
    }
};

// Helper function to test default constructor
std::string testDefaultConstructor() {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    Rectangle r_default;
    oss << "Default Rectangle: Length=" << r_default.getLength() << ", Width=" << r_default.getWidth() << ", Area=" << r_default.getArea() << std::endl;
    return oss.str();
}

// Helper function to test parameterized constructor
std::string testParameterizedConstructor(double l, double w) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    Rectangle r(l, w);
    oss << "Parameterized Rectangle: Length=" << r.getLength() << ", Width=" << r.getWidth() << ", Area=" << r.getArea() << std::endl;
    return oss.str();
}

int main() {
    std::cout << testDefaultConstructor();
    std::cout << testParameterizedConstructor(0.0, 0.0);
    std::cout << testParameterizedConstructor(5.0, 10.0);
    std::cout << testParameterizedConstructor(2.5, 4.0);
    std::cout << testParameterizedConstructor(-3.0, 5.0); // Robustness issue: negative length
    std::cout << testParameterizedConstructor(4.0, -2.0); // Robustness issue: negative width
    std::cout << testParameterizedConstructor(-1.0, -1.0); // Robustness issue: negative length and width
    return 0;
}