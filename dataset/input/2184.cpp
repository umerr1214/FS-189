#include <iostream>

class Circle {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double getRadius() const {
        return radius;
    }

    void setRadius(double r) { // Non-const member function
        radius = r;
    }
};

int main() {
    const Circle c(5.0); // Create a const Circle object
    std::cout << "Radius of const circle: " << c.getRadius() << std::endl;
    
    // Semantic error: Attempting to call a non-const method on a const object
    c.setRadius(10.0); 
    
    return 0;
}