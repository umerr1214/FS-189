#include <iostream>
#include <cmath> // For M_PI

class Shape {
public:
    // Semantic error: calculateArea is not virtual, preventing polymorphic behavior
    double calculateArea() { // Should be virtual double calculateArea()
        return 0.0;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double calculateArea() { // This method hides the base class method, does not override polymorphically
        return length * width;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double calculateArea() { // This method hides the base class method, does not override polymorphically
        return M_PI * radius * radius;
    }
};

int main() {
    Shape* s1 = new Rectangle(5.0, 4.0);
    Shape* s2 = new Circle(3.0);
    Rectangle rect_obj(10.0, 2.5);
    Circle circ_obj(5.0);

    // When calling through base class pointer, Shape::calculateArea() is called due to lack of 'virtual'
    std::cout << "Poly (Rect) Area: " << s1->calculateArea() << std::endl; // Will print 0.0
    std::cout << "Poly (Circ) Area: " << s2->calculateArea() << std::endl; // Will print 0.0

    // Direct calls to derived objects work correctly
    std::cout << "Direct Rect Area: " << rect_obj.calculateArea() << std::endl;
    std::cout << "Direct Circ Area: " << circ_obj.calculateArea() << std::endl;

    delete s1;
    delete s2;
    return 0;
}