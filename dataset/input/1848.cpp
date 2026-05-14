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
    // SEMANTIC ERROR: Destructor should be virtual for proper polymorphic cleanup.
    // If not virtual, only GeometricShape's destructor will be called when deleting via base pointer.
    ~GeometricShape() {
        std::cout << "GeometricShape destructor called." << std::endl;
    }
};

// Derived class Rectangle
class Rectangle : public GeometricShape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() override {
        return width * height;
    }
    std::string getName() {
        return "Rectangle";
    }
    ~Rectangle() {
        std::cout << "Rectangle destructor called." << std::endl;
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
        return 0.5 * base * height;
    }
    std::string getName() {
        return "Triangle";
    }
    ~Triangle() {
        std::cout << "Triangle destructor called." << std::endl;
    }
};

int main() {
    GeometricShape* rect = new Rectangle(5, 4);
    GeometricShape* tri = new Triangle(6, 3);

    std::cout << rect->getName() << " area: " << rect->getArea() << std::endl;
    std::cout << tri->getName() << " area: " << tri->getArea() << std::endl;

    std::cout << "\n--- Deleting shapes via base pointers ---" << std::endl;
    // Due to non-virtual destructor in GeometricShape,
    // only GeometricShape's destructor will be called, leading to resource leaks
    // or undefined behavior if derived classes manage resources.
    delete rect;
    delete tri;
    std::cout << "---------------------------------------" << std::endl;

    return 0;
}