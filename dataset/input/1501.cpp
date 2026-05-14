#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

class Vector2D {
private:
    double x;
    double y;

public:
    // Constructor with default arguments
    Vector2D(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

    // Robustness issue: Overloaded binary '+' operator modifies 'this' object
    // instead of returning a new one and leaves operands unchanged.
    // This violates the expected behavior of operator+ for value types,
    // causing side effects and unexpected state changes in the operands.
    Vector2D operator+(const Vector2D& other) {
        // Modifies the current object's coordinates
        this->x += other.x;
        this->y += other.y;
        // Returns the modified current object
        return *this;
    }

    // Friend declaration for the output stream operator
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v);
};

// Overload the output stream operator for easy printing
std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

int main() {
    // Set output precision for doubles
    std::cout << std::fixed << std::setprecision(1);

    // Test 1: Addition of two positive vectors
    Vector2D v1(1.0, 2.0);
    Vector2D v2(3.0, 4.0);
    Vector2D v3 = v1 + v2; // v1 is modified to (4.0, 6.0)
    std::cout << v3 << std::endl;
    std::cout << v1 << std::endl; // Prints modified v1

    // Test 2: Addition involving negative and decimal coordinates
    Vector2D v_neg1(-1.0, 2.5);
    Vector2D v_neg2(3.5, -4.0);
    Vector2D v_neg_res = v_neg1 + v_neg2; // v_neg1 is modified to (2.5, -1.5)
    std::cout << v_neg_res << std::endl;
    std::cout << v_neg1 << std::endl; // Prints modified v_neg1

    // Test 3: Chained addition
    Vector2D v_chain1(1.0, 1.0);
    Vector2D v_chain2(2.0, 2.0);
    Vector2D v_chain3(3.0, 3.0);
    // v_chain1 + v_chain2 modifies v_chain1 to (3.0, 3.0)
    // Then (modified v_chain1) + v_chain3 modifies v_chain1 again to (6.0, 6.0)
    Vector2D v_chain_res = v_chain1 + v_chain2 + v_chain3;
    std::cout << v_chain_res << std::endl;
    std::cout << v_chain1 << std::endl; // Prints modified v_chain1

    // Test 4: Addition with a zero vector
    Vector2D v_zero(0.0, 0.0);
    Vector2D v_nonzero(5.0, 6.0);
    Vector2D v_zero_res = v_zero + v_nonzero; // v_zero is modified to (5.0, 6.0)
    std::cout << v_zero_res << std::endl;
    std::cout << v_zero << std::endl; // Prints modified v_zero

    return 0;
}