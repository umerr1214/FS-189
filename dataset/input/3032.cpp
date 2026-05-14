#include <iostream>
#include <iomanip> // For std::fixed, std::setprecision

// Base class Shape
class Shape {
public:
    virtual double calculateArea() const = 0;
    virtual ~Shape() {} // Readability/Efficiency: Non-default virtual destructor, slightly less efficient than = default
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    float l; // Readability/Efficiency: Using float instead of double for member variables
    float w; // Readability/Efficiency: Using float instead of double for member variables

public:
    // Readability/Efficiency: No constructor, requiring manual setting of members
    void setDimensions(float length_val, float width_val) {
        l = length_val;
        w = width_val;
    }

    double calculateArea() const override {
        // Readability/Efficiency: Implicit conversion from float to double, potential precision loss.
        return static_cast<double>(l) * w;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    float r; // Readability/Efficiency: Using float instead of double for member variables

public:
    // Readability/Efficiency: No constructor, requiring manual setting of members
    void setRadius(float radius_val) {
        r = radius_val;
    }

    double calculateArea() const override {
        // Readability/Efficiency: Hardcoding PI using a float literal instead of M_PI or std::numbers::pi
        // This is less precise and less readable.
        const float PI_VAL = 3.14159f;
        return static_cast<double>(PI_VAL * r * r);
    }
};

int main() {
    // Set output precision for demonstration
    std::cout << std::fixed << std::setprecision(2);

    // Readability/Efficiency Issue: Using raw pointers and manual memory management (`new`/`delete`)
    // for demonstration, which is less safe and more verbose than stack objects or smart pointers.
    Shape* rect_ptr = new Rectangle();
    Shape* circle_ptr = new Circle();

    // Readability: Downcast to set dimensions because there are no constructors
    static_cast<Rectangle*>(rect_ptr)->setDimensions(5.0f, 4.0f);
    static_cast<Circle*>(circle_ptr)->setRadius(3.0f);

    std::cout << "Rectangle Area: " << rect_ptr->calculateArea() << std::endl;
    std::cout << "Circle Area: " << circle_ptr->calculateArea() << std::endl;

    // Readability/Efficiency Issue: Manual memory deallocation
    delete rect_ptr;
    delete circle_ptr;

    return 0;
}