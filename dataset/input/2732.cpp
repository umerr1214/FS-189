#include <iostream>
#include <cmath> // For pow, though direct multiplication is often more efficient for squares
#include <iomanip> // For std::fixed, std::setprecision

// Base class
class Shape {
public:
    virtual double calculateArea() { // Missing const qualifier
        return 0.0;
    }
    virtual ~Shape() = default;
};

// Derived class Square
class Square : public Shape {
private:
    double s_val; // Poor variable name for 'side'
public:
    Square(double s_val_param) : s_val(s_val_param) {} // Verbose parameter name

    double calculateArea() override { // Missing const qualifier, using pow for efficiency issue
        return pow(s_val, 2.0); // Less efficient than s_val * s_val
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double r_val; // Poor variable name for 'radius'
    // Define PI manually and with lower precision for readability/efficiency issue
    const float PI_CUSTOM = 3.14159f; 
public:
    Circle(double r_val_param) : r_val(r_val_param) {} // Verbose parameter name

    double calculateArea() override { // Missing const qualifier, using pow for efficiency issue, using custom PI
        return (double)PI_CUSTOM * pow(r_val, 2.0); // Less efficient and using a float PI constant
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(10);

    Square my_square(7.0);
    Circle my_circle(4.0);
    Shape* s_ptr1 = &my_square;
    Shape* s_ptr2 = &my_circle;

    std::cout << s_ptr1->calculateArea() << std::endl;
    std::cout << s_ptr2->calculateArea() << std::endl;

    Shape base_shape;
    std::cout << base_shape.calculateArea() << std::endl;

    return 0;
}