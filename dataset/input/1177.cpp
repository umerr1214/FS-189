#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    // Default constructor
    // Robustness issue: Not using initializer list, but assigning in body.
    // Also, the primary robustness issue here is the lack of const-correctness for getters.
    Point() {
        x = 0;
        y = 0;
    }

    // Parameterized constructor
    Point(int val_x, int val_y) {
        x = val_x;
        y = val_y;
    }

    // Robustness Issue: Getters are not const-qualified.
    // This means they cannot be called on const Point objects,
    // limiting the utility and safety of the class when used in const contexts.
    int getX() {
        return x;
    }

    int getY() {
        return y;
    }
};

int main() {
    // Test default constructor
    Point p1;
    std::cout << p1.getX() << " " << p1.getY() << std::endl;

    // Test parameterized constructor
    Point p2(5, 10);
    std::cout << p2.getX() << " " << p2.getY() << std::endl;

    // Test with negative coordinates
    Point p3(-3, 7);
    std::cout << p3.getX() << " " << p3.getY() << std::endl;

    return 0;
}