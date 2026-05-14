#include <iostream>
#include <string>
#include <sstream>

class Vector2D {
public:
    int x, y;
    Vector2D(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {}

    // Robustness Issue: Returns const Vector2D& instead of Vector2D&
    // This prevents chaining assignments or further modifications to the returned object
    // (e.g., (++vec).x = 10;), which is a common usage pattern for pre-increment.
    const Vector2D& operator++() {
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

    // This code demonstrates the robustness issue.
    // If uncommented, it would cause a compile-time error due to the 'const' return type:
    // "error: assignment of read-only member 'Vector2D::x'"
    // Vector2D v4(10, 20);
    // (++v4).x = 100;
    // To keep the program compilable, we test a simple increment for v4.
    Vector2D v4(10, 20);
    ++v4;
    std::cout << v4 << std::endl; // Expected: (11, 21) (after simple increment)

    return 0;
}