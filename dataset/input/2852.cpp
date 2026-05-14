#include <iostream>
#include <vector>
#include <memory> // For std::unique_ptr
#include <iomanip> // For std::fixed, std::setprecision

class Shape {
public:
    virtual void display() {
        // Efficiency/Readability Issue: Using std::endl unnecessarily flushes the buffer.
        std::cout << "This is a generic shape." << std::endl;
    }
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
public: // Readability Issue: Members are public, violating encapsulation.
    double width;
    double height;

public:
    // Readability Issue: Verbose constructor using 'this->' unnecessarily.
    Rectangle(double w, double h) {
        this->width = w;
        this->height = h;
    }

    void display() override {
        Shape::display(); // Call base class display
        
        // Readability Issue: Unnecessary temporary variables.
        double my_width_temp = this->width;
        double my_height_temp = this->height;

        std::cout << "Rectangle dimensions: Width = " << my_width_temp << ", Height = " << my_height_temp << "." << std::endl; // Excessive std::endl
        
        // Readability Issue: Another unnecessary temporary variable for area.
        double calculated_area_result = my_width_temp * my_height_temp;
        std::cout << "Area: " << calculated_area_result << "." << std::endl; // Excessive std::endl
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

    // Test Case 3: Another Rectangle with positive dimensions
    shapes.push_back(std::make_unique<Rectangle>(7.5, 2.0));

    for (size_t i = 0; i < shapes.size(); ++i) {
        std::cout << "--- Displaying Shape " << i + 1 << " ---\n";
        shapes[i]->display();
        std::cout << "\n"; // Add a newline for separation between shapes
    }

    return 0;
}