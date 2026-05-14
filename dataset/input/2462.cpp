#include <iostream>

class Vector2D {
public:
    // Readability/Efficiency Issue: Public members break encapsulation.
    double x;
    double y;

    Vector2D(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

    // Readability/Efficiency Issue: Parameters passed by value instead of const reference.
    // For larger objects, this would incur a performance penalty due to copying.
    Vector2D operator+(Vector2D other) const {
        Vector2D result;
        result.x = this->x + other.x;
        result.y = this->y + other.y;
        return result;
    }

    void print() const {
        std::cout.precision(2);
        std::cout << std::fixed << x << " " << y << std::endl;
    }
};

int main() {
    double x1, y1, x2, y2;

    // Read first vector
    if (!(std::cin >> x1 >> y1)) {
        return 1; // Input error
    }
    Vector2D v1(x1, y1);

    // Read second vector
    if (!(std::cin >> x2 >> y2)) {
        return 1; // Input error
    }
    Vector2D v2(x2, y2);

    // Perform vector addition
    Vector2D v3 = v1 + v2;

    // Print the result
    v3.print();

    return 0;
}