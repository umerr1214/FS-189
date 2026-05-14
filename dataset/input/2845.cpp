#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

// Base class Shape with a pure virtual function
class Shape {
public:
    // Pure virtual function to calculate area
    virtual double calculateArea() = 0;

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
    Rectangle(double l, double w) : length(l), width(w) {}

    // Implement the calculateArea() method for Rectangle
    // This implementation does not validate input, allowing negative dimensions
    // and resulting in negative or mathematically inconsistent areas.
    double calculateArea() override {
        return length * width;
    }

    // Optional: Getters for length and width (not strictly required by question, but good practice)
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