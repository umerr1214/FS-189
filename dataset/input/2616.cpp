#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    Point() : x(0), y(0) {}

    // SEMANTIC ERROR: getX is declared private, but the question explicitly asks for a public getter.
    // This will cause a compilation error when main() tries to call p.getX().
    int getX() const { // This method should be public
        return x;
    }

    // getY is correctly public
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
};

int main() {
    Point p;
    p.setX(10);
    p.setY(20);
    // Semantic Error: Attempting to call private method getX() from main
    std::cout << "Point coordinates: (" << p.getX() << ", " << p.getY() << ")\n"; // ERROR LINE

    p.setX(-5);
    p.setY(15);
    // Semantic Error: Attempting to call private method getX() from main
    std::cout << "Point coordinates: (" << p.getX() << ", " << p.getY() << ")\n"; // ERROR LINE

    p.setX(30);
    p.setY(-10);
    // Semantic Error: Attempting to call private method getX() from main
    std::cout << "Point coordinates: (" << p.getX() << ", " << p.getY() << ")\n"; // ERROR LINE

    return 0;
}