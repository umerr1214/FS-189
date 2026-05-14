#include <iostream>
#include <string>

class Shape {
protected:
    std::string color;
public:
    Shape(std::string c) : color(c) {}
    std::string getColor() const { return color; }
    void display() const {
        std::cout << "Shape color: " << color << std::endl;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    // LOGICAL ERROR: The constructor initializes the base class 'Shape' with a fixed color "Red"
    // instead of the 'c' parameter provided to the Circle constructor.
    Circle(std::string c, double r) : Shape("Red"), radius(r) {}

    double getRadius() const { return radius; }
    void display() const {
        std::cout << "Circle color: " << color << ", radius: " << radius << std::endl;
    }
};

int main() {
    Circle c("Blue", 5.0); // Expects color "Blue", but due to error, it will be "Red"
    c.display();
    
    Circle c2("Green", 10.0); // Expects color "Green", but will be "Red"
    c2.display();
    return 0;
}