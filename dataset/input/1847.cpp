#include <iostream>
#include <string>
#include <vector>

// Abstract base class
class GeometricShape {
public:
    virtual double getArea() = 0;
    std::string getName() {
        return "GeometricShape";
    }
    virtual ~GeometricShape() {}
};

// Derived class Rectangle
class Rectangle : public GeometricShape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() override {
        // LOGICAL ERROR: Should be width * height
        return width + height;
    }
    std::string getName() {
        return "Rectangle";
    }
};

// Derived class Triangle
class Triangle : public GeometricShape {
private:
    double base;
    double height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double getArea() override {
        // LOGICAL ERROR: Should be 0.5 * base * height
        return base * height;
    }
    std::string getName() {
        return "Triangle";
    }
};

int main() {
    Rectangle rect(5, 4); // Expected area: 20
    Triangle tri(6, 3);   // Expected area: 9 (0.5 * 6 * 3)

    std::cout << rect.getName() << " area: " << rect.getArea() << std::endl;
    std::cout << tri.getName() << " area: " << tri.getArea() << std::endl;

    std::vector<GeometricShape*> shapes;
    shapes.push_back(new Rectangle(10, 2)); // Expected area: 20
    shapes.push_back(new Triangle(8, 5));   // Expected area: 20

    for (const auto& shape : shapes) {
        std::cout << "Shape: " << shape->getName() << ", Area: " << shape->getArea() << std::endl;
    }

    for (const auto& shape : shapes) {
        delete shape;
    }

    return 0;
}