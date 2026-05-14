#include <iostream>

class Point {
private:
    int x;
    int y;
public:
    // Constructor with default values
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    // Method to print the Point coordinates
    void print() const {
        std::cout << "(" << x << ", " << y << ")";
    }

    // Robustness Issue:
    // This operator+ modifies the current object (left-hand operand)
    // and returns it, which is incorrect behavior for a binary addition operator.
    // Binary '+' should return a new object without altering its operands.
    Point operator+(const Point& other) {
        // Modifies 'this' object directly
        this->x += other.x;
        this->y += other.y;
        return *this; // Returns the modified current object
    }
};

int main() {
    std::cout << "--- Robustness Issue Test ---" << std::endl;

    // Test Case 1
    Point p1(1, 2);
    Point p2(3, 4);
    std::cout << "Initial p1: "; p1.print(); std::cout << std::endl;
    std::cout << "Initial p2: "; p2.print(); std::cout << std::endl;

    Point p3 = p1 + p2; // This line causes p1 to change in this incorrect version
    std::cout << "Result p3 = p1 + p2: "; p3.print(); std::cout << std::endl;
    std::cout << "p1 after addition (should NOT change for binary +): "; p1.print(); std::cout << std::endl;
    // Expected p3: (4, 6)
    // Expected p1 (if correct): (1, 2)
    // Actual p1 (with robustness issue): (4, 6)

    std::cout << std::endl;

    // Test Case 2
    Point p4(0, 0);
    Point p5(-1, -5);
    std::cout << "Initial p4: "; p4.print(); std::cout << std::endl;
    std::cout << "Initial p5: "; p5.print(); std::cout << std::endl;
    Point p6 = p4 + p5; // This line causes p4 to change
    std::cout << "Result p6 = p4 + p5: "; p6.print(); std::cout << std::endl;
    std::cout << "p4 after addition (should NOT change for binary +): "; p4.print(); std::cout << std::endl;
    // Expected p6: (-1, -5)
    // Expected p4 (if correct): (0, 0)
    // Actual p4 (with robustness issue): (-1, -5)

    return 0;
}