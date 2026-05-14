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
} // SYNTAX ERROR: Missing semicolon here

class Circle : public Shape {
private:
    double radius;
public:
    Circle(std::string c, double r) : Shape(c), radius(r) {}
    double getRadius() const { return radius; }
    void display() const {
        std::cout << "Circle color: " << color << ", radius: " << radius << std::endl;
    }
};

int main() {
    Circle c("Blue", 5.0);
    c.display();
    return 0;
}