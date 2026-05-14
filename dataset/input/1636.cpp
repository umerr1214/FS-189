#include <iostream>

class Rectangle {
private:
    double width;
    double height // Missing semicolon here, causing a syntax error

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() {
        return width * height;
    }
};

int main() {
    // This code will not compile due to the syntax error in the class definition.
    // If it were to compile, it would calculate areas correctly.
    Rectangle r1(5.0, 3.0);
    std::cout << "Area: " << r1.getArea() << std::endl;

    Rectangle r2(7.5, 2.0);
    std::cout << "Area: " << r2.getArea() << std::endl;

    return 0;
}