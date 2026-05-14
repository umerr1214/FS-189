#include <iostream>
#include <string>

// Base class Shape
class Shape {
protected:
    std::string color;
public:
    // READABILITY/EFFICIENCY ISSUE: Passing std::string by value.
    // This causes an unnecessary copy of the string object when the constructor is called.
    Shape(std::string c) {
        // READABILITY/EFFICIENCY ISSUE: Assigning member in constructor body instead of initializer list.
        // For complex objects like std::string, this means default-constructing 'color' then assigning,
        // which is less efficient than direct initialization via an initializer list.
        this->color = c;
        std::cout << "Shape constructor called for color: " << this->color << std::endl;
    }

    void printInfo() const {
        std::cout << "This is a Shape with color: " << color << std::endl;
    }

    // Destructor (non-virtual for this example, as it's not the primary issue here)
    ~Shape() {
        std::cout << "Shape destructor called for color: " << color << std::endl;
    }
};

// Derived class Circle
class Circle : public Shape {
private:
    double radius;
public:
    // READABILITY/EFFICIENCY ISSUE: Passing std::string by value.
    // This causes another unnecessary copy of the string object when the constructor is called.
    Circle(std::string c, double r) : Shape(c) { // Calls base constructor with a copied string
        // READABILITY/EFFICIENCY ISSUE: Assigning member in constructor body instead of initializer list.
        this->radius = r;
        std::cout << "Circle constructor called for radius: " << this->radius << std::endl;
    }

    void printInfo() const {
        std::cout << "This is a Circle with color: " << color << " and radius: " << radius << std::endl;
    }

    ~Circle() {
        std::cout << "Circle destructor called for radius: " << radius << std::endl;
    }
};

int main() {
    std::cout << "--- Creating Circle object ---" << std::endl;
    // Multiple string copies occur here due to pass-by-value in constructors
    Circle myCircle("Red", 10.5);
    myCircle.printInfo();

    std::cout << "--- Creating another Circle object ---" << std::endl;
    Circle anotherCircle("Green", 3.0);
    anotherCircle.printInfo();

    std::cout << "--- End of program ---" << std::endl;

    return 0;
}