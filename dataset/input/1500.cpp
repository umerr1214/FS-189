#include <iostream>

class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

    // Overload the binary + operator (SEMANTIC ERROR: modifies *this instead of returning a new object from non-mutating operation)
    // The question implies a non-mutating operation that returns a *new* object by value.
    // This implementation mutates 'this' (the left operand) and returns a reference to it.
    Vector2D& operator+(const Vector2D& other) { // Note: not 'const' here, and returns reference
        this->x += other.x; // Modifies current object
        this->y += other.y; // Modifies current object
        return *this;       // Returns a reference to the modified current object
    }

    void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    Vector2D v1(1.0, 2.0);
    Vector2D v2(3.0, 4.0);

    // With the incorrect operator+, v1 will be modified.
    // v3 will be a reference to the modified v1.
    Vector2D v3 = v1 + v2; 

    std::cout << "v1 after addition: ";
    v1.print(); 
    std::cout << "v2: ";
    v2.print(); 
    std::cout << "v3 (result): ";
    v3.print(); 

    return 0;
}