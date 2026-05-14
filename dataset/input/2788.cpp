#include <iostream>

class Vector2D {
public:
    double x;
    double y;

    Vector2D(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

    // Overload the + operator
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    void print() const {
        std::cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    Vector2D v1(1.0, 2.0);
    Vector2D v2(3.0, 4.0);
    Vector2D v3 = v1 + v2;
    // SYNTAX ERROR: Missing closing parenthesis for std::cout
    std::cout << "v1 + v2 = "; v3.print() << std::endl; 
    return 0;
}