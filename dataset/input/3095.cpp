#include <iostream>

class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D(double x_val, double y_val) : x(x_val), y(y_val) {}

    // Friend declaration for the overloaded insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v);
};

// Definition of the friend function outside the class
std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
    // LOGICAL ERROR: Prints y before x, violating the (x, y) format
    os << "(" << v.y << ", " << v.x << ")"; 
    return os;
}

int main() {
    Vector2D v1(1.0, 2.5);
    Vector2D v2(-3.0, 0.0);

    std::cout << "Vector 1: " << v1 << std::endl;
    std::cout << "Vector 2: " << v2 << std::endl;

    return 0;
}