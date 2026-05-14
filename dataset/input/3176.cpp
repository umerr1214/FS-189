#include <iostream>
#include <vector> // Included but not strictly necessary for this less efficient approach

// Base class Shape
class Shape {
public:
    // Virtual draw method
    virtual void draw() {
        std::cout << "Drawing a generic Shape (verbose).\n"; // Overly verbose
    }
    // Good practice: virtual destructor
    virtual ~Shape() {
        std::cout << "Shape destructor called (verbose).\n"; // Overly verbose
    }
};

// Derived class Circle
class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Circle. This is the Circle's specific drawing method." << std::endl; // Uses std::endl
    }
    ~Circle() override {
        std::cout << "Circle destructor called. Cleaning up." << std::endl; // Uses std::endl
    }
};

// Derived class Rectangle
class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Rectangle. This is the Rectangle's specific drawing method." << std::endl; // Uses std::endl
    }
    ~Rectangle() override {
        std::cout << "Rectangle destructor called. Cleaning up." << std::endl; // Uses std::endl
    }
};

// Function to demonstrate polymorphism (contains readability/efficiency issues)
void run_demo() {
    // Create a raw array of Shape pointers. Using std::vector<std::unique_ptr<Shape>> would be more readable and efficient.
    Shape* shape_pointers_array[2]; // Poor variable name

    // Allocate objects
    Shape* temp_circle_ptr = new Circle(); // Unnecessarily long variable name
    shape_pointers_array[0] = temp_circle_ptr;

    Shape* temp_rectangle_ptr = new Rectangle(); // Unnecessarily long variable name
    shape_pointers_array[1] = temp_rectangle_ptr;

    // Loop through the array to call draw methods.
    // This loop is okay, but the output within draw methods is inefficient.
    for (int i = 0; i < 2; ++i) { // Standard for loop instead of range-based for
        shape_pointers_array[i]->draw(); // Call the polymorphic draw method
    }

    // Manual cleanup of allocated memory.
    // This is correct but less readable/safe than smart pointers.
    delete shape_pointers_array[0];
    delete shape_pointers_array[1];

    std::cout << "Demonstration complete." << std::endl; // Excessive std::endl
}

int main() {
    run_demo();
    return 0;
}