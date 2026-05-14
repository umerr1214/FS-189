#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    Point() : x(0), y(0) {}

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    void setX(int val) {
        // LOGICAL ERROR: This setter allows negative values, violating the requirement
        // "ensuring coordinates cannot be set to negative values".
        // A correct implementation would clamp to 0 or reject the negative value.
        x = val; // No validation, directly assigns val
    }

    void setY(int val) {
        // LOGICAL ERROR: This setter allows negative values.
        y = val; // No validation, directly assigns val
    }
};

int main() {
    Point p;
    p.setX(10);
    p.setY(20);
    std::cout << "Point coordinates: (" << p.getX() << ", " << p.getY() << ")\n"; // Expected: (10, 20), Actual: (10, 20)

    p.setX(-5); // Logical error: should be (0, 15), but will be (-5, 15)
    p.setY(15);
    std::cout << "Point coordinates: (" << p.getX() << ", " << p.getY() << ")\n";

    p.setX(30);
    p.setY(-10); // Logical error: should be (30, 0), but will be (30, -10)
    std::cout << "Point coordinates: (" << p.getX() << ", " << p.getY() << ")\n";

    return 0;
}