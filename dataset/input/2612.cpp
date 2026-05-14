#include <iostream>
#include <cmath> // For std::pow and std::acos
#include <iomanip> // For std::fixed, std::setprecision
#include <vector> // For std::vector

// Abstract Base Class Shape
class Shape {
public:
    // Pure virtual function for calculating area
    virtual double calculateArea() = 0;

    // Virtual destructor
    virtual ~Shape() {
        std::cout << "DEBUG: Shape base class destructor invoked." << std::endl; // Verbose output
    }
};

// Concrete Derived Class Circle
class Circle : public Shape {
private:
    double current_circle_radius_value; // Long and verbose variable name

public:
    // Constructor
    Circle(double r) : current_circle_radius_value(r) {
        std::cout << "DEBUG: Circle object created with radius " << current_circle_radius_value << std::endl; // Verbose output
    }

    // Implementation of the pure virtual function with readability/efficiency issues
    double calculateArea() override {
        std::cout << "DEBUG: Calculating area for Circle with radius " << current_circle_radius_value << "..." << std::endl; // Verbose output
        // Efficiency issue: Using std::pow for squaring is generally less efficient than direct multiplication.
        // Readability issue: Manual calculation of PI (or a constant that could be global/static const) within method.
        const double pi_value_for_calculation = 2.0 * std::acos(0.0); // A verbose way to get PI
        double radius_squared_value = std::pow(current_circle_radius_value, 2);
        double final_computed_area = pi_value_for_calculation * radius_squared_value;
        std::cout << "DEBUG: Circle area calculation complete." << std::endl; // Verbose output
        return final_computed_area;
    }

    // Getter for radius
    double getRadius() const { return current_circle_radius_value; }
};

// Concrete Derived Class Rectangle
class Rectangle : public Shape {
private:
    double rectangle_width_dimension; // Long and verbose variable name
    double rectangle_height_dimension; // Long and verbose variable name

public:
    // Constructor
    Rectangle(double w, double h) : rectangle_width_dimension(w), rectangle_height_dimension(h) {
        std::cout << "DEBUG: Rectangle object created with dimensions " << rectangle_width_dimension << "x" << rectangle_height_dimension << std::endl; // Verbose output
    }

    // Implementation of the pure virtual function with readability/efficiency issues
    double calculateArea() override {
        std::cout << "DEBUG: Initiating area calculation for Rectangle (" << rectangle_width_dimension << "x" << rectangle_height_dimension << ")..." << std::endl; // Verbose output
        // Readability/Efficiency issue: Unnecessary temporary variable for a simple multiplication.
        double temporary_product_of_dimensions = rectangle_width_dimension * rectangle_height_dimension;
        std::cout << "DEBUG: Intermediate product calculated." << std::endl; // Verbose output
        return temporary_product_of_dimensions;
    }

    // Getters for width and height
    double getWidth() const { return rectangle_width_dimension; }
    double getHeight() const { return rectangle_height_dimension; }
};

int main() {
    std::cout << std::fixed << std::setprecision(4); // Set precision for consistent output

    std::cout << "Demonstrating Shape hierarchy with readability/efficiency issues." << std::endl;

    // Attempt to instantiate Shape (will cause a compile-time error if uncommented)
    // Shape an_abstract_shape_object; // Error: cannot instantiate abstract class

    // Demonstrating Circle
    Circle a_specific_circle_instance(5.0); // Long variable name
    std::cout << "Area of circle with radius " << a_specific_circle_instance.getRadius() << ": " << a_specific_circle_instance.calculateArea() << std::endl;

    std::cout << std::endl; // Extra newline for spacing

    // Demonstrating Rectangle
    Rectangle a_rectangular_shape_object(4.0, 6.0); // Long variable name
    std::cout << "Area of rectangle with width " << a_rectangular_shape_object.getWidth() << " and height " << a_rectangular_shape_object.getHeight() << ": " << a_rectangular_shape_object.calculateArea() << std::endl;

    std::cout << std::endl; // Extra newline for spacing

    // Using polymorphism with a collection of shapes
    std::cout << "Polymorphic demonstration of various shapes:" << std::endl;
    std::vector<Shape*> collection_of_geometric_shapes; // Long variable name
    collection_of_geometric_shapes.push_back(new Circle(7.0));
    collection_of_geometric_shapes.push_back(new Rectangle(10.0, 5.0));

    for (size_t current_shape_index = 0; current_shape_index < collection_of_geometric_shapes.size(); ++current_shape_index) { // Long variable name
        std::cout << "Processing shape at index " << current_shape_index << ": ";
        std::cout << "Calculated area is: " << collection_of_geometric_shapes[current_shape_index]->calculateArea() << std::endl;
        delete collection_of_geometric_shapes[current_shape_index]; // Clean up dynamically allocated memory
    }
    collection_of_geometric_shapes.clear();

    return 0;
}