#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    // Constructor
    Point(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {}

    // Getters for displaying (for test cases)
    // Note: These getters are const-correct, but the operator+ will not be robust.
    int getX() const { return x; }
    int getY() const { return y; }

    // Robustness Issue: operator+ returns a local object by reference,
    // leading to a dangling reference and undefined behavior.
    Point& operator+(const Point& other) {
        // Create a local Point object
        Point result(this->x + other.x, this->y + other.y);
        // Return a reference to this local object, which will be destroyed
        // as soon as the function returns. The caller receives a dangling reference.
        return result;
    }
};

int main() {
    Point p1(1, 2);
    Point p2(3, 4);
    Point& p_sum1_ref = p1 + p2; // p_sum1_ref now refers to a destroyed object
    // Accessing p_sum1_ref.getX() or p_sum1_ref.getY() is undefined behavior.
    // Depending on compiler, optimization, and runtime, it might print correct
    // values, garbage, or crash. This demonstrates the robustness issue.
    std::cout << "Sum 1: (" << p_sum1_ref.getX() << ", " << p_sum1_ref.getY() << ")\n";

    Point p3(-5, 10);
    Point p4(7, -3);
    Point& p_sum2_ref = p3 + p4;
    std::cout << "Sum 2: (" << p_sum2_ref.getX() << ", " << p_sum2_ref.getY() << ")\n";

    Point p5(0, 0);
    Point p6(100, -200);
    Point& p_sum3_ref = p5 + p6;
    std::cout << "Sum 3: (" << p_sum3_ref.getX() << ", " << p_sum3_ref.getY() << ")\n";

    return 0;
}