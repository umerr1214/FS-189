#include <iostream>

class Vector2D {
public:
    double x;
    double y;

    Vector2D(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

    // Robustness Issue: operator+ modifies *this instead of returning a new object.
    // This makes v1 + v2 modify v1, which is unexpected for a binary addition operator.
    Vector2D operator+(const Vector2D& other) {
        this->x += other.x;
        this->y += other.y;
        return *this; // Returns the modified current object
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
    Vector2D v3 = v1 + v2; // This will incorrectly modify v1

    // Print the result (v3 should be the sum, v1 should remain unchanged if operator+ was correct)
    v3.print();

    // Demonstrate the side effect: print v1 to show it has been modified
    // std::cerr << "v1 after addition: ";
    // v1.print(); // This would show the side effect in a real debug scenario

    return 0;
}