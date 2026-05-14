#include <iostream>
#include <string>
#include <vector> // For test cases in main

class Rectangle {
private:
    double length;
    double width;

public:
    // Constructor initializes with default valid values and then attempts to set using setters.
    // This allows initial validation, but the setters themselves have the robustness issue.
    Rectangle(double l, double w) : length(1.0), width(1.0) {
        setLength(l);
        setWidth(w);
    }

    double getLength() const { return length; }
    double getWidth() const { return width; }

    void setLength(double l) {
        // Robustness issue: Allows 0, but "positive" typically implies strictly > 0.
        if (l >= 0) {
            length = l;
        } else {
            std::cerr << "Error: Length must be positive. Value not updated." << std::endl;
        }
    }

    void setWidth(double w) {
        // Robustness issue: Allows 0, but "positive" typically implies strictly > 0.
        if (w >= 0) {
            width = w;
        } else {
            std::cerr << "Error: Width must be positive. Value not updated." << std::endl;
        }
    }

    double calculateArea() const { return length * width; }
    double calculatePerimeter() const { return 2 * (length + width); }
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