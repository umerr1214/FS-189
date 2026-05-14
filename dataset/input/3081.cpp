#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    // Constructor to initialize x and y
    Point(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {}

    // Getters for displaying coordinates (const-correct)
    int getX() const { return x; }
    int getY() const { return y; }

    // Overload the binary + operator as a member function
    // It is declared 'const' because it does not modify the current object.
    // It returns a new Point object representing the sum.
    Point operator+(const Point& other) const {
        // Efficiently constructs and returns a new Point object
        return Point(this->x + other.x, this->y + other.y);
    }
};

int main() {
    // Test Case 1: Positive coordinates
    Point p1(1, 2);
    Point p2(3, 4);
    Point p_sum1 = p1 + p2;
    std::cout << "Sum 1: (" << p_sum1.getX() << ", " << p_sum1.getY() << ")\n";

    // Test Case 2: Mixed positive and negative coordinates
    Point p3(-5, 10);
    Point p4(7, -3);
    Point p_sum2 = p3 + p4;
    std::cout << "Sum 2: (" << p_sum2.getX() << ", " << p_sum2.getY() << ")\n";

    // Test Case 3: Zero and larger coordinates
    Point p5(0, 0);
    Point p6(100, -200);
    Point p_sum3 = p5 + p6;
    std::cout << "Sum 3: (" << p_sum3.getX() << ", " << p_sum3.getY() << ")\n";

    // Demonstrate adding multiple points
    Point p7(1, 1);
    Point p8(2, 2);
    Point p9(3, 3);
    Point p_total = p7 + p8 + p9; // Chained addition
    std::cout << "Total Sum (p7+p8+p9): (" << p_total.getX() << ", " << p_total.getY() << ")\n";

    return 0;
}