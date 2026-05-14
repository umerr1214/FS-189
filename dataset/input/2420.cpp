#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // For std::fixed, std::setprecision

// Define PI using a preprocessor macro - readability/maintainability issue
#define MY_PI_VALUE 3.14159

// Base class
class Shape {
public:
    // Not marked const, even though it doesn't modify the object
    virtual double calculateArea() {
        return 0;
    }
    virtual ~Shape() {} // Not default, slightly less readable
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double m_rect_width_val; // Verbose and inconsistent naming
    double m_rect_height_val;

public:
    // No initializer list, less efficient for complex objects
    Rectangle(double w, double h) {
        m_rect_width_val = w;
        m_rect_height_val = h;
    }

    // Not marked const or override
    double calculateArea() {
        // Unnecessary temporary variables and steps
        double temp_w_storage = m_rect_width_val;
        double temp_h_storage = m_rect_height_val;
        double calculated_product = temp_w_storage * temp_h_storage;
        return calculated_product;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double m_circle_radius_val; // Verbose and inconsistent naming

public:
    Circle(double r) {
        m_circle_radius_val = r;
    }

    // Not marked const or override
    double calculateArea() {
        // Using #define for PI, and unnecessary intermediate variable
        double current_radius = m_circle_radius_val;
        double radius_multiplied_by_itself = current_radius * current_radius;
        return MY_PI_VALUE * radius_multiplied_by_itself;
    }
};