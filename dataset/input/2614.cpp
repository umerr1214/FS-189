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
        if (val >= 0) {
            x = val;
        } else {
            x = 0; // Clamping to 0 for negative values
        }
    }

    void setY(int val) {
        if (val >= 0) {
            y = val;
        } else {
            y = 0; // Clamping to 0 for negative values
        }
    }
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    Point p;
    p.setX(10);
    p.setY(20);
    std::cout << "Point coordinates: (" << p.getX() << ", " << p.getY() << ")\n";

    p.setX(-5); // Should be clamped to 0
    p.setY(15);
    std::cout << "Point coordinates: (" << p.getX() << ", " << p.getY() << ")\n";

    p.setX(30);
    p.setY(-10); // Should be clamped to 0
    std::cout << "Point coordinates: (" << p.getX() << ", " << p.getY() << ")\n";

    return 0;
}