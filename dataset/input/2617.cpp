#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    // Constructor to initialize
    Point() : x(0), y(0) {}
    Point(int initialX, int initialY) : x(initialX), y(initialY) {}

    // Getters (not const, but not the primary robustness issue highlighted)
    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    // Setters with validation that clamps negative values to 0 without explicit feedback
    void setX(int val) {
        if (val < 0) {
            x = 0; // Clamping to 0 silently
        } else {
            x = val;
        }
    }

    void setY(int val) {
        if (val < 0) {
            y = 0; // Clamping to 0 silently
        } else {
            y = val;
        }
    }
};

int main() {
    Point p1;
    std::cout << "Initial Point p1: (" << p1.getX() << ", " << p1.getY() << ")" << std::endl;

    p1.setX(10);
    p1.setY(20);
    std::cout << "After setting to (10, 20): (" << p1.getX() << ", " << p1.getY() << ")" << std::endl;

    // Test robustness issue: setting negative values
    p1.setX(-5); // Should become 0
    p1.setY(-15); // Should become 0
    std::cout << "After setting to (-5, -15) (clamped): (" << p1.getX() << ", " << p1.getY() << ")" << std::endl;

    p1.setX(30);
    p1.setY(-2); // Should become 0
    std::cout << "After setting to (30, -2) (clamped): (" << p1.getX() << ", " << p1.getY() << ")" << std::endl;

    return 0;
}