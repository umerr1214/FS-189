#include <iostream>

class Vector2D {
public:
    int x, y;
    Vector2D(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {}

    // Syntax Error: Missing parentheses for operator++
    Vector2D& operator++
    {
        x++;
        y++;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }
};

int main() {
    Vector2D v(1, 2);
    std::cout << "Original vector: " << v << std::endl;
    ++v;
    std::cout << "After pre-increment: " << v << std::endl;

    Vector2D v2(5, 5);
    Vector2D& ref_v2 = ++v2;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "ref_v2: " << ref_v2 << std::endl;

    return 0;
}