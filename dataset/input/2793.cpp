#include <iostream>
#include <ostream> // Required for std::ostream
#include <iomanip> // Required for std::fixed, std::setprecision
#include <sstream> // Required for std::stringstream in the driver

class Vector2D {
private: // Encapsulation: x and y are private members
    double x;
    double y;

public:
    // Default constructor: Initializes x and y to 0.0
    Vector2D() : x(0.0), y(0.0) {}

    // Parameterized constructor
    Vector2D(double x_val, double y_val) : x(x_val), y(y_val) {}

    // Method to print vector components to an output stream with fixed precision
    void print(std::ostream& os) const {
        os << "(" << std::fixed << std::setprecision(1) << x << ", " << std::fixed << std::setprecision(1) << y << ")";
    }

    // Friend declaration for the non-member binary + operator
    // This allows the operator to access private members x and y directly.
    friend Vector2D operator+(const Vector2D& v1, const Vector2D& v2);
};

// Non-member binary + operator overload
// Takes two constant references to Vector2D objects for efficiency and safety.
// Returns a new Vector2D object representing the sum.
Vector2D operator+(const Vector2D& v1, const Vector2D& v2) {
    return Vector2D(v1.x + v2.x, v1.y + v2.y);
}

int main() {
    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());

    // Test cases
    Vector2D v1(1.0, 2.0);
    Vector2D v2(3.0, 4.0);
    Vector2D v3 = v1 + v2;
    ss << "v1: "; v1.print(ss); ss << std::endl;
    ss << "v2: "; v2.print(ss); ss << std::endl;
    ss << "v1 + v2: "; v3.print(ss); ss << std::endl;

    Vector2D v4(-1.5, 0.5);
    Vector2D v5(2.0, -3.0);
    Vector2D v6 = v4 + v5;
    ss << "v4: "; v4.print(ss); ss << std::endl;
    ss << "v5: "; v5.print(ss); ss << std::endl;
    ss << "v4 + v5: "; v6.print(ss); ss << std::endl;

    std::cout.rdbuf(oldCout);
    std::cout << ss.str();
    return 0;
}