#include <iostream>
#include <string>
#include <sstream>

class Vector2D {
public:
    int x, y;
    Vector2D(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {}

    // Correct Version: Overloads pre-increment operator correctly
    // Increments x and y, modifies the object, and returns a reference to itself.
    Vector2D& operator++() {
        ++x;
        ++y;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector2D& vec) {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }
};

int main() {
    Vector2D v1(1, 2);
    ++v1;
    std::cout << v1 << std::endl; // Expected: (2, 3)

    Vector2D v2(0, 0);
    ++v2;
    std::cout << v2 << std::endl; // Expected: (1, 1)

    Vector2D v3(-5, 10);
    ++v3;
    std::cout << v3 << std::endl; // Expected: (-4, 11)

    // Test chaining, which should work correctly
    Vector2D v4(10, 20);
    (++v4).x = 100; // Should work fine
    std::cout << v4 << std::endl; // Expected: (100, 21)

    return 0;
}