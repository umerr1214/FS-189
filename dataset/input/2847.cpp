#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision
#include <algorithm> // For std::max (or could use a ternary operator)

// Base class Shape with a pure virtual function
class Shape {
public:
    // Pure virtual function to calculate area
    virtual double calculateArea() const = 0; // Mark as const as it doesn't modify the object

    // Virtual destructor for proper cleanup of derived classes
    virtual ~Shape() = default;
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    // Constructor to initialize length and width
    // Robustly handles non-positive dimensions by clamping them to 0.
    Rectangle(double l, double w)
        : length(std::max(0.0, l)), width(std::max(0.0, w)) {}

    // Implement the calculateArea() method for Rectangle
    // Marked as const as it does not modify the object's state.
    double calculateArea() const override {
        return length * width;
    }

    // Getters for length and width, marked as const for good practice
    double getLength() const { return length; }
    double getWidth() const { return width; }
};

int main() {
    // Driver code to test the Rectangle class
    double l, w;
    while (std::cin >> l >> w) {
        Rectangle rect(l, w);
        std::cout << std::fixed << std::setprecision(2) << rect.calculateArea() << std::endl;
    }
    return 0;
}