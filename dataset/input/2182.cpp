#include <iostream>

class Circle {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double getRadius() const {
        return radius;
    }

    void setRadius(double r) {
        radius = r;
    }
}; // Missing semicolon here, causing a syntax error

int main() {
    const Circle c(5.0);
    std::cout << "Radius of const circle: " << c.getRadius() << std::endl;
    // c.setRadius(10.0); // This would be a semantic error if the above compiled
    return 0;
}