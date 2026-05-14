#include <iostream>
#include <cmath> // For std::sqrt

class Vector2D {
public:
    double x;
    double y;

    Vector2D(double x_coord, double y_coord) : x(x_coord), y(y_coord) {}

    // getLength method
    double getLength() const {
        return std::sqrt(x * x + y * y);
    }
} // Syntax Error: Missing semicolon here

int main() {
    // Demonstrate calling on a const Vector2D object
    const Vector2D v1(3.0, 4.0);
    std::cout << "Vector v1: (" << v1.x << ", " << v1.y << ")" << std::endl;
    std::cout << "Length of v1: " << v1.getLength() << std::endl;

    Vector2D v2(5.0, 12.0);
    std::cout << "Vector v2: (" << v2.x << ", " << v2.y << ")" << std::endl;
    std::cout << "Length of v2: " << v2.getLength() << std::endl;

    return 0;
}