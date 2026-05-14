#define INCLUDE_PERIMETER // Define this macro for the correct version

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

class Rectangle {
private:
    double length;
    double width;

public:
    // Default constructor using initializer list
    Rectangle() : length(0.0), width(0.0) {}

    // Parameterized constructor using initializer list
    Rectangle(double l, double w) : length(l), width(w) {}

    // Getters for length and width
    double getLength() const {
        return length;
    }

    double getWidth() const {
        return width;
    }

    // Method to calculate area
    double getArea() const {
        return length * width;
    }

    // Optional: Add a perimeter method for more functionality
    double getPerimeter() const {
        return 2 * (length + width);
    }
};

// Helper function to test default constructor
std::string testDefaultConstructor() {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    Rectangle r_default;
    oss << "Default Rectangle: Length=" << r_default.getLength() << ", Width=" << r_default.getWidth() << ", Area=" << r_default.getArea();
    #ifdef INCLUDE_PERIMETER
    oss << ", Perimeter=" << r_default.getPerimeter();
    #endif
    oss << std::endl;
    return oss.str();
}

// Helper function to test parameterized constructor
std::string testParameterizedConstructor(double l, double w) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2);
    Rectangle r(l, w);
    oss << "Parameterized Rectangle: Length=" << r.getLength() << ", Width=" << r.getWidth() << ", Area=" << r.getArea();
    #ifdef INCLUDE_PERIMETER
    oss << ", Perimeter=" << r.getPerimeter();
    #endif
    oss << std::endl;
    return oss.str();
}

int main() {
    std::cout << testDefaultConstructor();
    std::cout << testParameterizedConstructor(0.0, 0.0);
    std::cout << testParameterizedConstructor(5.0, 10.0);
    std::cout << testParameterizedConstructor(2.5, 4.0);
    std::cout << testParameterizedConstructor(0.0, 7.0);
    return 0;
}