#include <iostream>
#include <string>
#include <vector> // For test cases in main

// Global constant for error message prefix - slightly better but still verbose
const std::string ERROR_PREFIX = "Validation Error: ";

class Rectangle {
private:
    double m_length; // Using m_ prefix for member variables (can be debated for readability)
    double m_width;

public:
    // Constructor initializes with default valid values and then attempts to set using setters.
    Rectangle(double l, double w) : m_length(1.0), m_width(1.0) {
        setLength(l);
        setWidth(w);
    }

    double getLength() const { return m_length; }
    double getWidth() const { return m_width; }

    void setLength(double newLength) {
        // Readability/Efficiency issue: Duplicated validation logic and error message generation
        if (newLength <= 0.0) {
            std::cerr << ERROR_PREFIX << "The provided length (" << newLength << ") must be strictly positive. Length was not updated." << std::endl;
        } else {
            m_length = newLength;
        }
    }

    void setWidth(double newWidth) {
        // Readability/Efficiency issue: Duplicated validation logic and error message generation
        if (newWidth <= 0.0) {
            std::cerr << ERROR_PREFIX << "The provided width (" << newWidth << ") must be strictly positive. Width was not updated." << std::endl;
        } else {
            m_width = newWidth;
        }
    }

    double calculateArea() const { return m_length * m_width; }
    double calculatePerimeter() const { return 2 * (m_length + m_width); }
};

// Helper function to run a set of tests and print output
void runTest(const std::string& testName, double initialL, double initialW,
             double setL1, double setW1, double setL2, double setW2) {
    std::cout << "\n--- " << testName << " ---" << std::endl;
    Rectangle r(initialL, initialW);
    std::cout << "Initial: L=" << r.getLength() << ", W=" << r.getWidth() << std::endl;
    r.setLength(setL1);
    r.setWidth(setW1);
    std::cout << "After first sets: L=" << r.getLength() << ", W=" << r.getWidth() << std::endl;
    r.setLength(setL2);
    r.setWidth(setW2);
    std::cout << "After second sets: L=" << r.getLength() << ", W=" << r.getWidth() << std::endl;
    std::cout << "Area: " << r.calculateArea() << ", Perimeter: " << r.calculatePerimeter() << std::endl;
}

int main() {
    runTest("Valid Initial & Updates", 10.0, 5.0, 12.0, 6.0, 15.0, 8.0);
    runTest("Initial Invalid, Valid Updates", -5.0, 0.0, 10.0, 4.0, 20.0, 10.0);
    runTest("Valid Initial, Invalid Updates", 10.0, 5.0, -3.0, 0.0, 1.0, -2.0);
    return 0;
}