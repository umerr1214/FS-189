#include <iostream>

class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D(double x_val, double y_val) : x(x_val), y(y_val) {}

    // Overload the + operator - Logical Error: performs subtraction
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y); // Should be x + other.x, y + other.y
    }

    void display() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    Vector2D v1(1.0, 2.0);
    Vector2D v2(3.0, 4.0);

    std::cout << "Vector v1: ";
    v1.display();
    std::cout << "Vector v2: ";
    v2.display();

    Vector2D v_sum = v1 + v2;
    std::cout << "Sum (v1 + v2): ";
    v_sum.display();

    Vector2D v3(-1.5, 0.5);
    Vector2D v4(1.5, -0.5);
    Vector2D v_sum2 = v3 + v4;
    std::cout << "Sum (v3 + v4): ";
    v_sum2.display();

    return 0;
}