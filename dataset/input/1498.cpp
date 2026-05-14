#include <iostream>

class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

    // Overload the binary + operator
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(this->x + other.x, this->y + other.y);
    } // ERROR: Missing semicolon here

    void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
} // ERROR: Missing semicolon after class definition

int main() {
    Vector2D v1(1.0, 2.0);
    Vector2D v2(3.0, 4.0);

    Vector2D v3 = v1 + v2;
    v3.print();

    return 0;
}