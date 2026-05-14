#include <iostream>

class Rectangle {
public:
    double width;
    double height;

    Rectangle(double w = 0, double h = 0) : width(w), height(h) {}

    // Semantic Error: Returns a copy of the object, not a reference.
    // This violates the requirement to return a reference to the current object (*this)
    // for method chaining, even though for this specific use case (calling a const method),
    // the observable output might appear correct because `calculateArea` operates on the temporary copy.
    Rectangle setDimensions(double w, double h) { // Should be Rectangle&
        width = w;
        height = h;
        return *this; // Returns a copy of the object
    }

    double calculateArea() const {
        return width * height;
    }
};

int main() {
    Rectangle rect;
    // The dimensions of 'rect' are set, but setDimensions returns a temporary copy.
    // calculateArea() is called on this temporary.
    rect.setDimensions(10, 5);
    std::cout << "Area: " << rect.calculateArea() << std::endl;

    Rectangle rect2;
    // setDimensions(7,3) returns a temporary copy, and calculateArea() is called on it.
    // The original 'rect2' object's dimensions are correctly set.
    double area = rect2.setDimensions(7, 3).calculateArea();
    std::cout << "Chained Area: " << area << std::endl;

    return 0;
}