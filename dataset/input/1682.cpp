#include <iostream>
#include <cmath> // For std::pow and M_PI

// Define M_PI if not available
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Base class Shape
class Shape {
public:
    // Virtual function to calculate area (no const)
    virtual double calculateArea() = 0;
    // Virtual destructor
    virtual ~Shape() = default;
};

// Derived class Circle
class Circle : public Shape {
private:
    double rad; // Less descriptive variable name

public:
    // Constructor for Circle (no const parameter)
    Circle(double r_val) : rad(r_val) {}

    // Override calculateArea for Circle
    // Uses std::pow for squaring, which is less efficient and readable than direct multiplication
    double calculateArea() override { // No const
        double result_val = M_PI * std::pow(rad, 2.0); // Inefficient squaring
        return result_val; // Unnecessary intermediate variable
    }
};

// Derived class Square
class Square : public Shape {
private:
    double s_len; // Less descriptive variable name

public:
    // Constructor for Square (no const parameter)
    Square(double len_val) : s_len(len_val) {}

    // Override calculateArea for Square
    // Uses std::pow for squaring
    double calculateArea() override { // No const
        return std::pow(s_len, 2.0); // Inefficient squaring
    }
};

int main() {
    // Demonstrating the classes with generic names
    Circle c_obj(5.0);
    Square s_obj(4.0);
    Circle another_c_obj(1.0);
    Square another_s_obj(10.0);

    std::cout << "Area of first circle: " << c_obj.calculateArea() << std::endl;
    std::cout << "Area of first square: " << s_obj.calculateArea() << std::endl;
    std::cout << "Area of second circle: " << another_c_obj.calculateArea() << std::endl;
    std::cout << "Area of second square: " << another_s_obj.calculateArea() << std::endl;
    std::cout << "Area of circle with radius 0.0: " << Circle(0.0).calculateArea() << std::endl;
    std::cout << "Area of square with side 0.0: " << Square(0.0).calculateArea() << std::endl;

    return 0;
}