#include <iostream>
#include <string>
#include <vector>
#include <memory> // For std::unique_ptr

// Abstract base class GeometricShape
class GeometricShape {
public:
    // Pure virtual function for calculating area
    virtual double getArea() const = 0;

    // Non-virtual function for getting shape name
    std::string getName() const {
        return name_;
    }

    // Virtual destructor for proper cleanup of derived objects
    virtual ~GeometricShape() = default;

protected:
    std::string name_; // Consistent and concise naming
};

// Derived class Rectangle
class Rectangle : public GeometricShape {
public:
    // Constructor with input validation for robustness
    Rectangle(double width, double height) : width_(width), height_(height) {
        if (width_ <= 0 || height_ <= 0) {
            // A more robust solution might throw an exception or return an error code.
            // For this example, we'll set invalid dimensions to 0 to avoid negative area.
            std::cerr << "Warning: Rectangle dimensions must be positive. Setting to 0 for invalid inputs." << std::endl;
            width_ = (width_ <= 0) ? 0 : width_;
            height_ = (height_ <= 0) ? 0 : height_;
        }
        name_ = "Rectangle";
    }

    // Implementation of getArea for Rectangle
    double getArea() const override {
        return width_ * height_;
    }

private:
    double width_;
    double height_;
};

// Derived class Triangle
class Triangle : public GeometricShape {
public:
    // Constructor with input validation for robustness
    Triangle(double base, double height) : base_(base), height_(height) {
        if (base_ <= 0 || height_ <= 0) {
            std::cerr << "Warning: Triangle dimensions must be positive. Setting to 0 for invalid inputs." << std::endl;
            base_ = (base_ <= 0) ? 0 : base_;
            height_ = (height_ <= 0) ? 0 : height_;
        }
        name_ = "Triangle";
    }

    // Implementation of getArea for Triangle
    double getArea() const override {
        return 0.5 * base_ * height_;
    }

private:
    double base_;
    double height_;
};

int main() {
    // Use std::vector of std::unique_ptr for automatic memory management and polymorphism
    std::vector<std::unique_ptr<GeometricShape>> shapes;

    // Valid shapes
    shapes.push_back(std::make_unique<Rectangle>(5.0, 4.0));
    shapes.push_back(std::make_unique<Triangle>(6.0, 3.0));
    shapes.push_back(std::make_unique<Rectangle>(10.5, 2.5));
    shapes.push_back(std::make_unique<Triangle>(7.0, 8.0));

    // Test cases with invalid dimensions (handled gracefully by constructors)
    shapes.push_back(std::make_unique<Rectangle>(-5.0, 4.0)); // Should warn and set width to 0
    shapes.push_back(std::make_unique<Triangle>(0.0, 10.0));  // Should warn and set base to 0
    shapes.push_back(std::make_unique<Rectangle>(-2.0, -3.0)); // Should warn and set both to 0

    std::cout << "--- Shape Areas ---" << std::endl;
    for (const auto& shape : shapes) {
        std::cout << shape->getName() << " Area: " << shape->getArea() << std::endl;
    }

    // Memory is automatically managed by unique_ptr, no explicit deletes needed

    return 0;
}