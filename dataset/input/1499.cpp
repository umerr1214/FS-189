#include <iostream>

class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

    // Overload the binary + operator (LOGICAL ERROR: performs subtraction)
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(this->x - other.x, this->y - other.y); // Should be '+'
    }

    void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    Vector2D v1(1.0, 2.0);
    Vector2D v2(3.0, 4.0);

    Vector2D v3 = v1 + v2; // Expected: (4.0, 6.0), Actual: (-2.0, -2.0)
    v3.print();

    return 0;
}