#include <iostream>
#include <string>
#include <algorithm> // For std::max
#include <iomanip>   // For std::fixed and std::setprecision

class Rectangle {
private:
    double m_length; // Clear and consistent member naming
    double m_width;

public:
    // Constructor with default arguments, uses initializer list for efficiency and clarity.
    // Dimensions are clamped to a minimum of 0.0 for robustness against negative inputs.
    Rectangle(double length = 1.0, double width = 1.0)
        : m_length(std::max(0.0, length)), m_width(std::max(0.0, width)) {}

    // Constant getter methods for safe access to member data
    double getLength() const {
        return m_length;
    }

    double getWidth() const {
        return m_width;
    }

    double getArea() const {
        return m_length * m_width;
    }

    // Constant method to display information
    void displayInfo(const std::string& name) const {
        std::cout << name << ": Length = " << std::fixed << std::setprecision(1) << m_length
                  << ", Width = " << std::fixed << std::setprecision(1) << m_width
                  << ", Area = " << std::fixed << std::setprecision(1) << getArea() << std::endl;
    }
};

int main() {
    // Demonstrate creating Rectangle objects
    
    // 1. Using default arguments (length = 1.0, width = 1.0)
    Rectangle r1;
    r1.displayInfo("Rectangle A (Default)");

    // 2. Using one argument (length = 5.0, width = 1.0)
    Rectangle r2(5.0);
    r2.displayInfo("Rectangle B (One argument)");

    // 3. Using both arguments (length = 3.0, width = 4.0)
    Rectangle r3(3.0, 4.0);
    r3.displayInfo("Rectangle C (Both arguments)");

    // Demonstrate robust handling of negative input dimensions
    Rectangle r_robust_handled(-2.0, 5.0);
    r_robust_handled.displayInfo("Rectangle D (Robustly handled)");

    return 0;
}