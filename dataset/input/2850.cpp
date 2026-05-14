#include <iostream>

class Shape {
public:
    // Semantic Error: 'display' is not virtual in the base class
    void display() {
        std::cout << "This is a generic shape." << std::endl;
    }
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const {
        return width * height;
    }

    // Semantic Error: Attempting to override a non-virtual function
    void display() override {
        std::cout << "Rectangle dimensions: Width = " << width
                  << ", Height = " << height << std::endl;
        std::cout << "Area: " << getArea() << std::endl;
    }
};

int main() {
    Shape* s1 = new Shape();
    Shape* s2 = new Rectangle(5.0, 10.0);

    s1->display();
    s2->display();

    delete s1;
    delete s2;
    return 0;
}