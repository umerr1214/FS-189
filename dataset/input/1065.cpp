#include <iostream>

class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D(double x_val, double y_val) : x(x_val), y(y_val) {}

    // Overload the + operator - Semantic Error: modifies the left operand (this)
    // instead of returning a new object and keeping operands constant.
    // The question explicitly states "returning a new Vector2D object".
    Vector2D operator+(const Vector2D& other) { // Not const, implying modification
        this->x += other.x; // Modifies 'this' (the left operand)
        this->y += other.y; // Modifies 'this' (the left operand)
        return *this;       // Returns the modified 'this'
    }

    void display() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    Vector2D v1(1.0, 2.0);
    Vector2D v2(3.0, 4.0);

    std::cout << "Initial Vector v1: ";
    v1.display();
    std::cout << "Vector v2: ";
    v2.display();

    Vector2D v_sum = v1 + v2; // v1 is modified here
    std::cout << "Sum (v1 + v2): ";
    v_sum.display();
    std::cout << "Vector v1 after addition: "; // This will show the modified v1
    v1.display();

    std::cout << "\n--- Second Test ---\n";
    Vector2D v3(-1.5, 0.5);
    Vector2D v4(1.5, -0.5);

    std::cout << "Initial Vector v3: ";
    v3.display();
    std::cout << "Vector v4: ";
    v4.display();

    Vector2D v_sum2 = v3 + v4; // v3 is modified here
    std::cout << "Sum (v3 + v4): ";
    v_sum2.display();
    std::cout << "Vector v3 after addition: "; // This will show the modified v3
    v3.display();

    return 0;
}