#include <iostream>

class Point2D {
private:
    int x;
    int y;

public:
    Point2D(int x_coord = 0, int y_coord = 0) : x(x_coord), y(y_coord) {}

    int getX() const { return x; }
    int getY() const { return y; }

    void display() const {
        std::cout << "(" << x << ", " << y << ")";
    }

    // Semantic Error: Returning a reference to a local variable 'result'
    // which will be destroyed upon function exit, leading to undefined behavior.
    Point2D& operator+(const Point2D& other) const {
        Point2D result; // Local variable
        result.x = this->x + other.x;
        result.y = this->y + other.y;
        return result; // Returning reference to a temporary object
    }
};

int main() {
    Point2D p1(1, 2);
    Point2D p2(3, 4);
    Point2D p3 = p1 + p2; // Accessing p3 will lead to undefined behavior

    std::cout << "p1: "; p1.display(); std::cout << std::endl;
    std::cout << "p2: "; p2.display(); std::cout << std::endl;
    std::cout << "p1 + p2: "; p3.display(); std::cout << std::endl;

    Point2D p4(0, 0);
    Point2D p5(-1, 5);
    Point2D p6 = p4 + p5; // Accessing p6 will lead to undefined behavior

    std::cout << "p4: "; p4.display(); std::cout << std::endl;
    std::cout << "p5: "; p5.display(); std::cout << std::endl;
    std::cout << "p4 + p5: "; p6.display(); std::cout << std::endl;

    Point2D p7(10, -5);
    Point2D p8(2, 7);
    Point2D p9 = p7 + p8; // Accessing p9 will lead to undefined behavior

    std::cout << "p7: "; p7.display(); std::cout << std::endl;
    std::cout << "p8: "; p8.display(); std::cout << std::endl;
    std::cout << "p7 + p8: "; p9.display(); std::cout << std::endl;

    return 0;
}