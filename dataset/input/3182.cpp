#include <iostream>
#include <cmath> // Required for std::pow, even if M_PI is not used

// No cmath for M_PI, define it manually and less precisely as a macro
#define PI_VALUE 3.14159 // Less precise than M_PI and a macro is generally less safe than const double

// Abstract base class
class Shape {
public:
    virtual ~Shape() { /* An explicit empty destructor is often unnecessary when default is sufficient */ }
    virtual double calculateArea() = 0;
};

// Concrete class Circle
class Circle : public Shape {
private:
    double rad; // Poor variable name: 'rad' instead of 'radius'

public:
    Circle(double r_val) { // Less idiomatic constructor syntax and poor parameter name
        rad = r_val;
    }

    double calculateArea() override {
        // Inefficient: uses std::pow() instead of simple multiplication (rad * rad)
        // Relies on the macro PI_VALUE.
        double area_val = PI_VALUE * std::pow(rad, 2.0);
        return area_val;
    }
};

// Concrete class Rectangle
class Rectangle : public Shape {
private:
    double wd; // Poor variable name: 'wd' instead of 'width'
    double ht; // Poor variable name: 'ht' instead of 'height'

public:
    Rectangle(double w_val, double h_val) : wd(w_val), ht(h_val) {
        // Constructor is okay, but variable names are poor.
    }

    double calculateArea() override {
        // Calculation is simple, but relies on poorly named member variables
        return wd * ht;
    }
};

// A utility function that isn't particularly useful or well-placed, adds clutter
void print_separator() {
    std::cout << "--------------------" << std::endl;
}

int main() {
    Circle c_obj(5.0);
    Rectangle r_obj(4.0, 5.0);

    print_separator(); // Unnecessary separator print
    // Confusing output with redundant calculateArea calls and derived values
    std::cout << "Area of a circular object with radius " << c_obj.calculateArea() / PI_VALUE << " (calculated using inefficient method): " << c_obj.calculateArea() << std::endl;
    print_separator();

    // Confusing output with redundant calculateArea calls and derived values
    std::cout << "Area of a rectangular object with dimensions " << r_obj.calculateArea() / r_obj.wd << " by " << r_obj.wd << ": " << r_obj.calculateArea() << std::endl;
    print_separator();

    // More instances to show repetition in main
    Circle another_circle(10.0);
    Rectangle another_rectangle(7.0, 3.0);

    print_separator();
    std::cout << "Another circle's area: " << another_circle.calculateArea() << std::endl;
    print_separator();
    std::cout << "Another rectangle's area: " << another_rectangle.calculateArea() << std::endl;
    print_separator();

    return 0;
}