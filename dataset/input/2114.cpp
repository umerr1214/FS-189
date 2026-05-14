#include <iostream>
#include <vector>
#include <string>
// No <memory> for this one, sticking to raw pointers for readability contrast

// Base class
class Shape {
public:
    virtual double calculateArea() const = 0;
    virtual ~Shape() {} // Virtual destructor is essential for proper cleanup
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double w_val; // Unclear variable name
    double h_val; // Unclear variable name
public:
    Rectangle(double w, double h) : w_val(w), h_val(h) {}
    double calculateArea() const override {
        return w_val * h_val;
    }
};

// Derived class: Circle
class Circle : public Shape {
private:
    double rad; // Unclear variable name
public:
    Circle(double r) : rad(r) {}
    double calculateArea() const override {
        const double P_VAL = 3.14; // Less precise PI, "magic number"
        return P_VAL * rad * rad;
    }
};

int main() {
    std::vector<Shape*> shape_collection; // Less descriptive variable name

    // Storing instances
    shape_collection.push_back(new Rectangle(12.0, 6.0));
    shape_collection.push_back(new Circle(8.0));
    shape_collection.push_back(new Rectangle(4.0, 9.0));
    shape_collection.push_back(new Circle(3.0));

    std::cout << "Calculating areas (Readability / Efficiency Issue):\n";
    // Iterate using an old-style loop, less concise than range-based for
    for (size_t i = 0; i < shape_collection.size(); ++i) {
        Shape* current_shape_ptr = shape_collection[i]; // Extra variable, slightly less efficient access
        std::cout << "Area " << (i + 1) << ": " << current_shape_ptr->calculateArea() << std::endl;
    }

    // Manual memory cleanup - correct, but less readable/safe than smart pointers
    for (Shape* s_ptr : shape_collection) {
        delete s_ptr;
    }
    shape_collection.clear(); // Clear vector after deleting contents

    return 0;
}