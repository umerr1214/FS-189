#include <iostream>
#include <string>
#include <vector>
#include <cmath> // For M_PI
#include <iomanip> // For std::fixed, std::setprecision
#include <algorithm> // For std::max

// Base class
class Shape {
public:
    // Virtual destructor is good practice for polymorphic base classes
    virtual ~Shape() = default;

    // Public method calculateArea() returns 0 for the base class
    // Marked const as it doesn't modify the object state
    virtual double calculateArea() const {
        return 0;
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double m_width;
    double m_height;

public:
    // Constructor uses initializer list and validates input (dimensions must be non-negative)
    Rectangle(double width, double height)
        : m_width(std::max(0.0, width)), m_height(std::max(0.0, height)) {}

    // Overrides calculateArea() and is marked const and override
    double calculateArea() const override {
        return m_width * m_height;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double m_radius;

public:
    // Constructor uses initializer list and validates input (radius must be non-negative)
    Circle(double radius)
        : m_radius(std::max(0.0, radius)) {}

    // Overrides calculateArea() and is marked const and override
    double calculateArea() const override {
        return M_PI * m_radius * m_radius;
    }
};