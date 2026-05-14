#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision
#include <cmath>   // Not strictly needed for this 'inefficient' approach, but common.

// Base class Shape with a pure virtual function
class ShapeBaseClass { // Poor class name
public:
    // Pure virtual function to calculate area
    virtual double calc_area_func() = 0; // Poor function name

    // Virtual destructor for proper cleanup of derived classes
    virtual ~ShapeBaseClass() = default;
};

// Derived class Rectangle
class Rectangle_Class : public ShapeBaseClass { // Poor class name
private:
    double len; // Poor variable name
    double wid; // Poor variable name

public:
    // Constructor to initialize length and width
    Rectangle_Class(double input_length, double input_width) : len(input_length), wid(input_width) {
        // This constructor just assigns values. No validation.
    }

    // Implement the calculateArea() method for Rectangle
    // This implementation is inefficient and prone to floating-point inaccuracies.
    double calc_area_func() override {
        // This is a highly inefficient way to multiply two numbers.
        // It simulates integration by summing tiny strips.
        // The direct multiplication 'len * wid' would be much faster and more accurate.
        double current_total_area = 0.0;
        const double iteration_step_size = 0.001; // A very small step for "accuracy"

        // Loop through the length, adding 'width * step' for each tiny segment.
        // This introduces significant overhead and floating-point accumulation errors.
        for (double x_coordinate = 0; x_coordinate < len; x_coordinate += iteration_step_size) {
            current_total_area += wid * iteration_step_size; // Summing up width * dx
        }
        // If length is negative, the loop condition 'x_coordinate < len' (e.g., x < -3.0)
        // will immediately be false, resulting in an area of 0.0.
        // This is a side effect, not explicit robust handling.

        return current_total_area; // Return the calculated area.
    }

    // Getters with inconsistent naming and no const correctness
    double get_len() { return len; }
    double get_wid() { return wid; }
};

int main() {
    // Driver code to test the Rectangle_Class
    double l_input, w_input; // Poor variable names
    while (std::cin >> l_input >> w_input) {
        Rectangle_Class my_rectangle_object(l_input, w_input); // Overly verbose object name
        std::cout << std::fixed << std::setprecision(2) << my_rectangle_object.calc_area_func() << std::endl;
    }
    return 0;
}