#include <iostream>

class Vector2D {
public:
    double x;
    double y;

    Vector2D(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

    // Overload the + operator with a logical error
    Vector2D operator+(const Vector2D& other) const {
        // Logical error: only adds x components, keeps 'this' y component
        return Vector2D(x + other.x, y); // Should be y + other.y
    }

    void print() const {
        std::cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    Vector2D v1(1.0, 2.0);
    Vector2D v2(3.0, 4.0);
    Vector2D v3 = v1 + v2; // Expected (4.0, 6.0), Actual (4.0, 2.0)

    std::cout << "Vector v1: "; v1.print(); std::cout << std::endl;
    std::cout << "Vector v2: "; v2.print(); std::cout << std::endl;
    std::cout << "v1 + v2 = "; v3.print(); std::cout << std::endl;

    Vector2D v4(0.5, 1.5);
    Vector2D v5(2.5, 0.5);
    Vector2D v6 = v4 + v5; // Expected (3.0, 2.0), Actual (3.0, 1.5)
    std::cout << "v4 + v5 = "; v6.print(); std::cout << std::endl;

    return 0;
}