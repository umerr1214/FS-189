#include <iostream>

class Point {
  private:
    int x;
    int y;

  public:
                                Point() { x = 0; y = 0; } // Default constructor
    Point(int initialX, int initialY) {
                                                x = initialX;
                                                y = initialY;
    }

    // Getters - not const, a common quality/readability issue
    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    // Setters with validation. Validation is mostly correct, but code style is poor.
    void setX(int val) {
        if (val < 0) {
            // Do nothing if negative, which is one way to "ensure coordinates cannot be set to negative"
        } else {
            x = val;
        }
    }

    void setY(int val) {
        if (val < 0) {
            // Do nothing
        } else {
            y = val;
        }
    }
};

int main() {
    Point p;
    std::cout << "Initial: (" << p.getX() << ", " << p.getY() << ")\n"; // Inconsistent newline style

    p.setX(5);
    p.setY(10);
    std::cout << "Set (5,10): (" << p.getX() << ", " << p.getY() << ")\n";

    p.setX(-3); // Should not change x
    p.setY(-7); // Should not change y
    std::cout << "Tried setting (-3,-7): (" << p.getX() << ", " << p.getY() << ")\n";

    if (p.getX() == 5 && p.getY() == 10) {
        std::cout << "Validation successful for negative inputs.\n";
    } else {
        std::cout << "Validation failed for negative inputs.\n";
    }

    p.setX(25);
    p.setY(30);
    std::cout << "Set (25,30): (" << p.getX() << ", " << p.getY() << ")\n";

    return 0;
}