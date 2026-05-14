#include <iostream>
#include <cmath> // For M_PI, std::pow
#include <vector>
#include <iomanip> // For std::fixed, std::setprecision

// Readability/Efficiency Issue: using namespace std; in global scope
using namespace std;

// Base class Shape
class Shape {
protected:
    // Readability Issue: Redundant member not used effectively
    string shape_identifier; 
public:
    Shape() : shape_identifier("Generic Shape") {}
    virtual double calculateArea() const {
        return 0.0;
    }
    virtual ~Shape() = default; 
};

// Derived class Rectangle
class Rectangle : public Shape {
private:
    double m_width; // Readability Issue: Poor variable naming style (m_ prefix for private is acceptable, but inconsistency with other files/standard practice)
    double m_height;
public:
    Rectangle(double w, double h) : m_width(w), m_height(h) {
        this->shape_identifier = "Rectangle"; // Readability Issue: Unnecessary use of 'this->'
    }

    // Readability Issue: Missing 'override' keyword
    // Efficiency Issue: Uses std::pow(x, 1.0) which is less efficient than direct multiplication
    double calculateArea() const { 
        return std::pow(this->m_width, 1.0) * std::pow(this->m_height, 1.0); // Readability Issue: Unnecessary use of 'this->'
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double m_radius; // Readability Issue: Poor variable naming style
public:
    Circle(double r) : m_radius(r) {
        this->shape_identifier = "Circle"; // Readability Issue: Unnecessary use of 'this->'
    }

    // Readability Issue: Missing 'override' keyword
    // Efficiency Issue: Defines M_PI locally, possibly re-initializing it on every call.
    // Also uses std::pow(r, 2.0) which is less efficient than r * r.
    double calculateArea() const {
        const double PI_VAL = M_PI; // Efficiency Issue: local constant, could be global or member to avoid re-initialization
        return PI_VAL * std::pow(this->m_radius, 2.0); // Readability Issue: Unnecessary use of 'this->'
    }
};

// Driver code for test cases
int main() {
    cout << fixed << setprecision(2);

    // Test Case 1: Valid Rectangle
    Rectangle rect1(5.0, 4.0);
    cout << "Rectangle (5x4) area: " << rect1.calculateArea() << endl;

    // Test Case 2: Rectangle with zero dimensions
    Rectangle rect2(0.0, 10.0);
    cout << "Rectangle (0x10) area: " << rect2.calculateArea() << endl;

    // Test Case 3: Valid Circle
    Circle circ1(3.0);
    cout << "Circle (radius 3) area: " << circ1.calculateArea() << endl;

    // Test Case 4: Circle with zero radius
    Circle circ2(0.0);
    cout << "Circle (radius 0) area: " << circ2.calculateArea() << endl;

    // Test Case 5: Polymorphic calls
    vector<Shape*> shapes;
    shapes.push_back(new Rectangle(10.5, 2.0));
    shapes.push_back(new Circle(5.5));

    for (const auto& shape : shapes) {
        cout << "Polymorphic Shape Area: " << shape->calculateArea() << endl;
    }

    // Clean up
    for (const auto& shape : shapes) {
        delete shape;
    }

    return 0;
}