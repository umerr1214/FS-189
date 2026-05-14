#include <iostream>
#include <cmath>   // For M_PI, std::pow
#include <iomanip> // For std::fixed and std::setprecision

// Base class
class Shape {
public:
    // Pure virtual function for calculating area
    virtual double calculateArea() const = 0; // Missing 'override' keyword
    // Virtual destructor is present, which is good practice
    virtual ~Shape() {}
};

// Derived class: Circle
class Circle : public Shape {
private:
    double rad_val; // Poor variable name
public:
    Circle(double r) : rad_val(r) {}
    // Missing 'override' keyword.
    // Using std::pow for squaring is less efficient than simple multiplication (rad_val * rad_val).
    double calculateArea() const {
        return M_PI * std::pow(rad_val, 2);
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double wid_val; // Poor variable name
    double hgt_val; // Poor variable name
public:
    Rectangle(double w, double h) : wid_val(w), hgt_val(h) {}
    // Missing 'override' keyword.
    double calculateArea() const {
        return wid_val * hgt_val;
    }
};

int main() {
    // Using a raw array with a magic number for its size
    Shape* shape_pointers_array[3]; // Poor variable name, fixed size

    // Redundant temporary variables for initialization values
    double r1 = 5.0;
    double w1 = 4.0;
    double h1 = 6.0;
    double r2 = 2.5;

    shape_pointers_array[0] = new Circle(r1);
    shape_pointers_array[1] = new Rectangle(w1, h1);
    shape_pointers_array[2] = new Circle(r2);

    std::cout << "Calculating areas of various shapes (Readability/Efficiency Issue):" << std::endl;
    std::cout << std::fixed << std::setprecision(4); // Set precision for consistent output

    // Using a C-style for loop instead of a more readable range-based for loop
    for (int i = 0; i < 3; ++i) { // Magic number '3' again
        Shape* current_shape_ptr = shape_pointers_array[i]; // Unnecessary temporary variable
        std::cout << "Shape " << (i + 1) << " area is: " << current_shape_ptr->calculateArea() << std::endl;
    }

    // Manual memory cleanup. While correct, it's error-prone and less readable than RAII (smart pointers).
    for (int i = 0; i < 3; ++i) {
        delete shape_pointers_array[i];
        shape_pointers_array[i] = nullptr; // Good practice, but still manual
    }

    return 0;
}