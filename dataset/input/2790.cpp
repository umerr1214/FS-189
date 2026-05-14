#include <iostream>

class Vector2D {
public:
    double x;
    double y;

    Vector2D(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

    // Overload the + operator with a semantic error: modifies 'this' object
    // instead of returning a new one, violating the typical semantic of binary '+'
    // and the question's requirement to "return a new Vector2D object".
    Vector2D& operator+(const Vector2D& other) { // Returns a reference, and modifies 'this'
        this->x += other.x;
        this->y += other.y;
        return *this; // Returns reference to modified 'this'
    }

    void print() const {
        std::cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    Vector2D v1(1.0, 2.0);
    Vector2D v2(3.0, 4.0);
    
    std::cout << "Before addition:" << std::endl;
    std::cout << "Vector v1: "; v1.print(); std::cout << std::endl; // (1, 2)
    std::cout << "Vector v2: "; v2.print(); std::cout << std::endl; // (3, 4)

    // This line will modify v1 directly
    Vector2D v3 = v1 + v2; // v1 becomes (4, 6), v3 is a copy of modified v1

    std::cout << "After addition:" << std::endl;
    std::cout << "Vector v1: "; v1.print(); std::cout << std::endl; // Expected (1,2), Actual (4,6)
    std::cout << "Vector v2: "; v2.print(); std::cout << std::endl; // (3,4)
    std::cout << "v1 + v2 (v3) = "; v3.print(); std::cout << std::endl; // (4,6)

    // Chained addition will also behave unexpectedly
    Vector2D v4(10.0, 10.0);
    Vector2D v5(1.0, 1.0);
    Vector2D v6(2.0, 2.0);
    // (v4 + v5) + v6
    // v4 becomes (11,11)
    // then (11,11) + v6 -> v4 becomes (13,13)
    // v7 is a copy of the final v4
    Vector2D v7 = (v4 + v5) + v6;
    std::cout << "Chained addition (v4 + v5) + v6 = "; v7.print(); std::cout << std::endl; // (13,13)
    std::cout << "Original v4 after chained addition: "; v4.print(); std::cout << std::endl; // (13,13) - this is the semantic error

    return 0;
}