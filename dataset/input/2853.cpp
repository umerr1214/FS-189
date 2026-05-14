#include <iostream>
#include <vector>
#include <memory> // For std::unique_ptr
#include <iomanip> // For std::fixed, std::setprecision

class Shape {
public:
    virtual void display() {
        std::cout << "This is a generic shape.\n";
    }
    virtual ~Shape() = default; // Good practice: virtual destructor for polymorphic base class
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    // Concise constructor using member initializer list
    Rectangle(double w, double h) : width(w), height(h) {
        // Optional: Add validation here for robustness, e.g., if (w < 0 || h < 0) throw std::invalid_argument("Dimensions cannot be negative.");
    }

    // Use 'override' keyword for clarity and compile-time checking
    void display() override {
        Shape::display(); // Call base class display to get generic info
        std::cout << "Rectangle dimensions: Width = " << width
                  << ", Height = " << height << ".\n";
        double area = width * height; // Direct and efficient area calculation
        std::cout << "Area: " << area << ".\n";
    }
};

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;

    // Set precision for all output for consistent formatting
    std::cout << std::fixed << std::setprecision(2);

    // Test Case 1: Generic Shape
    shapes.push_back(std::make_unique<Shape>());

    // Test Case 2: Rectangle with positive dimensions
    shapes.push_back(std::make_unique<Rectangle>(10.0, 5.0));

    // Test Case 3: Another Rectangle with positive dimensions
    shapes.push_back(std::make_unique<Rectangle>(7.5, 2.0));

    for (size_t i = 0; i < shapes.size(); ++i) {
        std::cout << "--- Displaying Shape " << i + 1 << " ---\n";
        shapes[i]->display();
        std::cout << "\n"; // Add a newline for separation between shapes
    }

    return 0;
}