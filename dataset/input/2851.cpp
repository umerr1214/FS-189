#include <iostream>
#include <vector>
#include <memory> // For std::unique_ptr
#include <iomanip> // For std::fixed, std::setprecision

class Shape {
public:
    virtual void display() {
        std::cout << "This is a generic shape.\n";
    }
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    // Robustness Issue: No validation for width and height.
    // Negative dimensions are allowed, leading to incorrect area calculation.
    Rectangle(double w, double h) : width(w), height(h) {}

    void display() override {
        Shape::display(); // Call base class display
        std::cout << "Rectangle dimensions: Width = " << width
                  << ", Height = " << height << ".\n";
        double area = width * height; // Area calculation without validation
        std::cout << "Area: " << area << ".\n";
    }
};

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;

    // Set precision for all output
    std::cout << std::fixed << std::setprecision(2);

    // Test Case 1: Generic Shape
    shapes.push_back(std::make_unique<Shape>());

    // Test Case 2: Rectangle with positive dimensions
    shapes.push_back(std::make_unique<Rectangle>(10.0, 5.0));

    // Test Case 3: Rectangle with negative width (Robustness Issue test)
    shapes.push_back(std::make_unique<Rectangle>(-8.0, 4.0));
    
    // Test Case 4: Rectangle with negative height
    shapes.push_back(std::make_unique<Rectangle>(6.0, -3.0));

    for (size_t i = 0; i < shapes.size(); ++i) {
        std::cout << "--- Displaying Shape " << i + 1 << " ---\n";
        shapes[i]->display();
        std::cout << "\n"; // Add a newline for separation between shapes
    }

    return 0;
}