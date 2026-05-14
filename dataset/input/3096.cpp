#include <iostream>

class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D(double x_val, double y_val) : x(x_val), y(y_val) {}

    // SEMANTIC ERROR: Missing 'friend' declaration for operator<<
    // friend std::ostream& operator<<(std::ostream& os, const Vector2D& v);
};

// Definition of the non-member function outside the class
// It attempts to access private members x and y without being a friend.
std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
    os << "(" << v.x << ", " << v.y << ")"; // Semantic error: Direct access to private members
    return os;
}

int main() {
    Vector2D v1(1.0, 2.5);
    Vector2D v2(-3.0, 0.0);

    std::cout << "Vector 1: " << v1 << std::endl;
    std::cout << "Vector 2: " << v2 << std::endl;

    return 0;
}