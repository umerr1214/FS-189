#include <iostream>
#include <ostream> // Required for std::ostream
#include <iomanip> // Required for std::fixed, std::setprecision
#include <sstream> // Required for std::stringstream in the driver

class Vector2D {
public:
    double x;
    double y;

    // Readability Issue: Less descriptive parameter names (_x, _y)
    Vector2D(double _x, double _y) : x(_x), y(_y) {}

    // Default constructor for convenience (correctly initializes members)
    Vector2D() : x(0.0), y(0.0) {}

    // Method to print vector components to an output stream
    // Readability Issue: Using `this->` for member access when not necessary
    void print(std::ostream& os) const {
        os << "(" << std::fixed << std::setprecision(1) << this->x << ", " << std::fixed << std::setprecision(1) << this->y << ")";
    }
};

// Overloaded binary + operator - Readability/Efficiency Issue:
// Takes arguments by value, leading to unnecessary copies of Vector2D objects.
Vector2D operator+(Vector2D v1, Vector2D v2) { // v1 and v2 are copied here
    return Vector2D(v1.x + v2.x, v1.y + v2.y);
}

int main() {
    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());

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