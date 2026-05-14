#include <iostream>

class Shape {
public:
    virtual void display() {
        std::cout << "This is a generic shape." << std::endl;
    }
    virtual ~Shape() {}
} // Syntax Error: Missing semicolon here

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const {
        return width * height;
    }

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