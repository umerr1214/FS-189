#include <iostream>
#include <string>
#include <sstream>

class Vector2D {
public:
    int x, y;
    Vector2D(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {}

    // Readability / Efficiency Issue: Uses x = x + 1; instead of ++x;
    // For fundamental types like int, '++x' is generally more idiomatic, concise,
    // and can be marginally more efficient (though compilers often optimize 'x = x + 1'
    // to '++x' for built-in types).
    Vector2D& operator++() {
        x = x + 1; // Less idiomatic/concise than ++x;
        y = y + 1; // Less idiomatic/concise than ++y;
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

    // Test chaining, which should work correctly here
    Vector2D v4(10, 20);
    (++v4).x = 100; // Should work fine
    std::cout << v4 << std::endl; // Expected: (100, 21)

    return 0;
}