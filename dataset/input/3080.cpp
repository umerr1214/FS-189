#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    // Constructor
    Point(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {}

    // Getters for displaying
    int getX() const { return x; }
    int getY() const { return y; }

    // Readability/Efficiency Issue:
    // 1. The operator+ is not declared 'const', which is a minor best practice/readability issue.
    // 2. The implementation creates a temporary object and then assigns its members,
    //    which is less efficient than direct initialization in the return statement.
    Point operator+(const Point& other) { // Not const
        Point temporaryResult; // Unnecessary default construction
        temporaryResult.x = this->x + other.x; // Assignment
        temporaryResult.y = this->y + other.y; // Assignment
        return temporaryResult; // Return by value (incurs copy/move)
    }
};

int main() {
    Point p1(1, 2);
    Point p2(3, 4);
    Point p_sum1 = p1 + p2;
    std::cout << "Sum 1: (" << p_sum1.getX() << ", " << p_sum1.getY() << ")\n";

    Point p3(-5, 10);
    Point p4(7, -3);
    Point p_sum2 = p3 + p4;
    std::cout << "Sum 2: (" << p_sum2.getX() << ", " << p_sum2.getY() << ")\n";

    Point p5(0, 0);
    Point p6(100, -200);
    Point p_sum3 = p5 + p6;
    std::cout << "Sum 3: (" << p_sum3.getX() << ", " << p_sum3.getY() << ")\n";

    return 0;
}